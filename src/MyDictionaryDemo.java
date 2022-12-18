import java.awt.*;//����awt��
import java.awt.event.*; //����awt.event��
import javax.swing.*;//����swing��
import javax.swing.border.*;//����swing.border��
import javax.swing.filechooser.*;//����swing.filechooser��

/* 
 * ��������JFrame�����࣬ʵ����ActionListener�ӿ�
 */
public class MyDictionaryDemo extends JFrame implements ActionListener {
    private static final long serialVersionUID = 776572726716394096L;// ���л�
    private JMenuBar menuBar; // �˵���
    private JMenu fileMenu, editMenu, toolMenu; // �ļ��˵����༭�˵������߲˵�
    private JPanel showDicName; // ��ʾ����ʿ���
    private JTextField dicDisplay; // ��ʾ�ʿ��ı���
    private JPanel showSelect; // ��ʾӢ�������ѡ��ť
    private JPanel showSeek; // ��ʾ��ѯ
    private JPanel showButton; // ��ʾ����
    private JTextArea wordSeek; // ��ѯ�����
    private ButtonGroup bg; // ��ѡ��ť
    private JRadioButton jrb1, jrb2; // �㰴ť
    private JEditorPane showText; // ������ʾ���
    private JButton butt; // ��ѯ��ť

    private MyDictionary myDictionary = new MyDictionary(); // �ʵ���
    private String dicfileName; // ����ʵ���
    private boolean isEnToCh = true; // �Ƿ���Ӣ�뺺�Ĳ�����������¼ʹ���ߵ�ѡ��
    private boolean isImport = false; // �Ƿ���ʿ�Ĳ�����������¼ʹ���ߵ������

    /* ������ */
    public static void main(String[] args) {
        MyDictionaryDemo frame = new MyDictionaryDemo();
        frame.setVisible(true);
    }

    /* ��Ƴ�ʼ��� */
    public MyDictionaryDemo() {
        setTitle("Ӣ��˫��ʵ�");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // JPanel panel = new JPanel();
        // panel.setSize(400, 500);
        // panel.setVisible(true);
        // panel.setOpaque(false);
        // add(panel);

        // ��������
        JPanel panelTop = new JPanel();
        panelTop.setOpaque(false);// ����͸��
        panelTop = (JPanel) getContentPane();// ����ΪcontentPane
        panelTop.setBorder(new EmptyBorder(5, 5, 5, 5));

        setBounds(500, 200, 400, 500);
        setVisible(true);
        panelTop.setLayout(null);

        setJMenuBar(createMenuBar()); // ��Ӳ˵���
        panelTop.add(creatShowDicName());// �����ʾ����ʿ���
        panelTop.add(creatShowSelect());// ѡ������Ӣ����Ӣ����
        panelTop.add(creatShowSeek());// ��Ӳ�ѯ����
        panelTop.add(creatShowButton()); // ��Ӳ�ѯ��ť
        panelTop.add(creatShowText()); // ������崰��

    }

    /* ��Ʋ˵���������ͨ������ʵ��ѡ�񣬰�סAlt����ʾ���� */
    private JMenuBar createMenuBar() {
        menuBar = new JMenuBar();
        fileMenu = new JMenu("�ļ�(F)");
        fileMenu.setMnemonic(KeyEvent.VK_F);

        createOneMenuItem("����ʿ�(O)", KeyEvent.VK_O, fileMenu);
        createOneMenuItem("����ʿ�(S)", KeyEvent.VK_S, fileMenu);
        fileMenu.addSeparator();
        createOneMenuItem("�˳�(Q)", KeyEvent.VK_Q, fileMenu);
        menuBar.add(fileMenu);

        editMenu = new JMenu("�༭(E)");
        editMenu.setMnemonic(KeyEvent.VK_E);
        createOneMenuItem("��ӵ���(A)", KeyEvent.VK_A, editMenu);
        createOneMenuItem("�޸ĵ���(M)", KeyEvent.VK_M, editMenu);
        createOneMenuItem("ɾ������(D)", KeyEvent.VK_D, editMenu);
        menuBar.add(editMenu);

        toolMenu = new JMenu("����(T)");
        toolMenu.setMnemonic(KeyEvent.VK_Q);
        createOneMenuItem("���뵥�ʵ����ʿ�(N)", KeyEvent.VK_N, toolMenu);
        menuBar.add(toolMenu);

        return menuBar;
    }

    /* ���õ����˵�������¼������� */
    private JMenuItem createOneMenuItem(String lable, int mnemonic, JMenu menu) {
        JMenuItem menuItem = new JMenuItem(lable);
        menuItem.setMnemonic(mnemonic);
        menuItem.addActionListener(this);
        menu.add(menuItem);
        return menuItem;
    }

    /* ������ʾ����ʿ�������� */
    private JPanel creatShowDicName() {
        showDicName = new JPanel();
        dicDisplay = new JTextField();
        dicDisplay.setEditable(false);
        dicDisplay.setText("��δ����ʿ�");
        showDicName.add(dicDisplay);
        showDicName.setBounds(5, 5, 375, 30);
        return showDicName;

    }

    /* ����Ӣ����ѡ����� */
    private JPanel creatShowSelect() {
        showSelect = new JPanel();
        bg = new ButtonGroup();
        jrb1 = new JRadioButton("Ӣ����");
        jrb2 = new JRadioButton("����Ӣ");
        jrb1.addActionListener(this);
        jrb2.addActionListener(this);
        bg.add(jrb1);
        bg.add(jrb2);
        showSelect.add(jrb1);
        showSelect.add(jrb2);
        showSelect.setBounds(5, 35, 375, 50);
        return showSelect;
    }

    /* ���ò�ѯ������� */
    private JPanel creatShowSeek() {
        showSeek = new JPanel();
        wordSeek = new JTextArea();
        wordSeek.setColumns(20);
        showSeek.add(wordSeek);
        showSeek.setBounds(5, 85, 375, 50);

        return showSeek;
    }

    /* ���ò�ѯ��ť��� */
    private JPanel creatShowButton() {
        showButton = new JPanel();
        butt = new JButton("��ѯ");
        butt.addActionListener(this);
        showButton.add(butt);
        showButton.setBounds(5, 135, 375, 50);

        return showButton;
    }

    /* ����������ʾ��� */
    private JEditorPane creatShowText() {
        showText = new JEditorPane();
        showText.setContentType("text/html");
        showText.setEditable(false);
        showText.setBounds(5, 185, 375, 220);

        return showText;
    }

    /* ��Ӧ��ť */
    @Override
    public void actionPerformed(ActionEvent e) {
        if ("����ʿ�(O)".equals(e.getActionCommand())) {
            dicfileName = new String(); // ��ʼ������ʿ�
            // �����ļ�ѡ�񴰿�
            JFileChooser jfc = new JFileChooser();
            FileNameExtensionFilter filter = new FileNameExtensionFilter("txt", "txt");
            jfc.setDialogTitle("��ѡ���ļ�");
            jfc.setFileFilter(filter);
            int ret = jfc.showOpenDialog(null);
            if (ret != JFileChooser.APPROVE_OPTION) {
                return;
            }
            dicfileName = jfc.getSelectedFile().getAbsolutePath();
            // ����MyDictionary��ķ�������ʿ�txt�ļ���map
            myDictionary.FileToDict(dicfileName);
            JOptionPane.showMessageDialog(this, "�ѳɹ�����", null, JOptionPane.INFORMATION_MESSAGE);
            isImport = true;
            dicDisplay.setText(dicfileName.substring(dicfileName.lastIndexOf("\\") + 1, dicfileName.lastIndexOf(".")));// ȥ������Ҫ�ַ���ʾ����
        }
        if ("����ʿ�(S)".equals(e.getActionCommand())) {
            // �����ļ�ѡ�񴰿�
            JFileChooser jfc = new JFileChooser();
            jfc.setDialogTitle("���Ϊ");
            jfc.showSaveDialog(null);
            jfc.setVisible(true);
            String file = jfc.getSelectedFile().getAbsolutePath();
            // ����MyDictionary�ķ�������map������ݵ�txt�ļ�
            myDictionary.DictToFile(file);
            JOptionPane.showMessageDialog(this, "�ѳɹ�����", null, JOptionPane.INFORMATION_MESSAGE);
        }
        if ("�˳�(Q)".equals(e.getActionCommand())) {
            System.exit(0);
        }
        if ("��ӵ���(A)".equals(e.getActionCommand())) {
            // �����µĴ���AddFrame
            new AddFrame(this).setVisible(true);
        }
        if ("�޸ĵ���(M)".equals(e.getActionCommand())) {
            // �����µĴ���ModFrame
            new ModFrame(this).setVisible(true);
        }
        if ("ɾ������(D)".equals(e.getActionCommand())) {
            // �����µĴ���DelFrame
            new DelFrame(this).setVisible(true);
        }
        if ("���뵥�ʵ����ʿ�(N)".equals(e.getActionCommand())) {
            // �����µĴ���AddWordToNoteFrame
            new AddWordToNoteFrame(this).setVisible(true);
        }
        if ("Ӣ����".equals(e.getActionCommand())) {
            // ����bool����
            isEnToCh = true;
        }
        if ("����Ӣ".equals(e.getActionCommand())) {
            isEnToCh = false;
        }
        if ("��ѯ".equals(e.getActionCommand())) {
            String text = wordSeek.getText();
            // һЩ������
            if (isImport == false) {
                // ����û�δ��������ʾ�û�
                JOptionPane.showMessageDialog(this, "��δ����ʿ⣡", null, JOptionPane.WARNING_MESSAGE);
                return;
            }
            if (text.isEmpty()) {
                // ����û�����Ϊ������ʾ�û�
                JOptionPane.showMessageDialog(this, "������Ҫ��ѯ�ĵ��ʣ�", null, JOptionPane.WARNING_MESSAGE);
                return;
            }
            if (isEnToCh) {
                if (myDictionary.searchWordEntoCh2(text) == null) {
                    JOptionPane.showMessageDialog(this, "Ҫ��ѯ�ĵ��ʲ����ڣ�", null, JOptionPane.WARNING_MESSAGE);
                    showText.setText("");
                    return;
                } else
                    showText.setText(myDictionary.searchWordEntoCh2(text));
            } else {
                if (myDictionary.searchWordChtoEn2(text) == null) {
                    JOptionPane.showMessageDialog(this, "Ҫ��ѯ�����Ĳ����ڣ�", null, JOptionPane.WARNING_MESSAGE);
                    showText.setText("");
                    return;
                } else
                    // �������ı�����ʾ���壬ʹ����MyDictionary���searchWordChtoEn2����
                    showText.setText(myDictionary.searchWordChtoEn2(text));
            }
        }
    }
    //���ص���ʿ���
    public String getfileName() {
        return dicfileName;
    }
    //����MyDictionary��
    public MyDictionary getMydictionary() {
        return myDictionary;
    }
}

/* �����ӵ��ʵ���� */
class AddFrame extends JFrame {

    private JPanel contentPane;
    private JPanel showWord;
    private JPanel showMeaning;
    private JPanel showButton;
    private JLabel wordLabel;
    private JLabel meaningLabel;
    private JTextField textWord;
    private JEditorPane textMeaning;
    private JButton button1;
    private JButton button2;

    public AddFrame(MyDictionaryDemo dicDemo) {
        setTitle("�༭(��ӵ���)");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(510, 210, 300, 400);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));//��Ե�Ű�
        setContentPane(contentPane);

        showWord = new JPanel();
        showWord.setLayout(new FlowLayout());
        wordLabel = new JLabel("����:");
        textWord = new JTextField();
        textWord.setColumns(20);
        showWord.add(wordLabel);
        showWord.add(textWord);
        contentPane.add(showWord, BorderLayout.NORTH);

        showMeaning = new JPanel();
        showMeaning.setLayout(null);
        meaningLabel = new JLabel("����:");
        meaningLabel.setBounds(9, 40, 30, 20);
        textMeaning = new JEditorPane();
        textMeaning.setBounds(45, 40, 220, 190);

        showMeaning.add(meaningLabel);
        showMeaning.add(textMeaning);
        contentPane.add(showMeaning, BorderLayout.CENTER);

        showButton = new JPanel();
        showButton.setLayout(new BorderLayout(0, 0));
        button1 = new JButton("ȡ��");
        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
        button2 = new JButton("���");
        button2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = textWord.getText();
                String meaning = textMeaning.getText();
                if (name.isEmpty()) {
                    do_button_actionPerformed1(e);
                    return;
                }
                if (!dicDemo.getMydictionary().addWord2(name, meaning)) {
                    do_button_actionPerformed2(e);
                    return;
                } else {
                    do_button_actionPerformed3(e);
                    return;
                }
            }
        });
        showButton.add(button1, BorderLayout.WEST);
        showButton.add(button2, BorderLayout.EAST);
        contentPane.add(showButton, BorderLayout.SOUTH);
    }

    //һЩ������ʾ
    protected void do_button_actionPerformed1(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "��������Ҫ��ӵĵ��ʣ�", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed2(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "��ӵĵ��ʴ��ڣ�", null, JOptionPane.INFORMATION_MESSAGE);
    }

    protected void do_button_actionPerformed3(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "�ɹ���ӣ�", null, JOptionPane.WARNING_MESSAGE);
    }

}

/* ����޸ĵ��ʵ���� */
class ModFrame extends JFrame {

    private JPanel contentPane;
    private JPanel showWord;
    private JPanel showMeaning;
    private JPanel showButton;
    private JLabel wordLabel;
    private JLabel meaningLabel;
    private JTextField textWord;
    private JEditorPane textMeaning;
    private JButton button1;
    private JButton button2;
    private JButton button3;

    public ModFrame(MyDictionaryDemo dicDemo) {
        setTitle("�༭(�޸ĵ���)");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(520, 220, 300, 400);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));//��Ե����
        setContentPane(contentPane);

        showWord = new JPanel();
        showWord.setLayout(new FlowLayout());
        wordLabel = new JLabel("����:");
        textWord = new JTextField();
        textWord.setColumns(20);
        showWord.add(wordLabel);
        showWord.add(textWord);
        contentPane.add(showWord, BorderLayout.NORTH);

        showMeaning = new JPanel();
        showMeaning.setLayout(null);
        meaningLabel = new JLabel("����:");
        meaningLabel.setBounds(9, 40, 30, 20);
        textMeaning = new JEditorPane();
        textMeaning.setBounds(45, 40, 220, 190);

        showMeaning.add(meaningLabel);
        showMeaning.add(textMeaning);
        contentPane.add(showMeaning, BorderLayout.CENTER);

        showButton = new JPanel();
        showButton.setLayout(new BorderLayout(0, 0));
        button1 = new JButton("ȡ��");
        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });

        button2 = new JButton("��ѯ");
        button2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = textWord.getText();
                if (name.isEmpty()) {
                    do_button_actionPerformed1(e);
                    return;
                }
                if (dicDemo.getMydictionary().searchWordEntoCh2(name) == null) {
                    do_button_actionPerformed2(e);
                    return;
                } else {
                    textMeaning.setText(dicDemo.getMydictionary().searchWordEntoCh2(name));
                    return;
                }

            }
        });

        button3 = new JButton("ȷ��");
        button3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = textWord.getText();
                String meaning = textMeaning.getText();
                if (name.isEmpty()) {
                    do_button_actionPerformed1(e);
                    return;
                }
                if (!dicDemo.getMydictionary().modifyWord2(name, meaning)) {
                    do_button_actionPerformed2(e);
                    return;
                } else {
                    do_button_actionPerformed3(e);
                    return;
                }
            }
        });
        showButton.add(button1, BorderLayout.WEST);
        showButton.add(button2, BorderLayout.CENTER);
        showButton.add(button3, BorderLayout.EAST);
        contentPane.add(showButton, BorderLayout.SOUTH);
    }
    //һЩ������ʾ
    protected void do_button_actionPerformed1(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "������Ҫ�޸ĵĵ��ʣ�", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed2(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "Ҫ�޸ĵĵ��ʲ����ڣ�", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed3(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "�޸ĳɹ���", null, JOptionPane.WARNING_MESSAGE);
    }

}

/* ���ɾ�����ʵ���� */
class DelFrame extends JFrame {

    private JPanel contentPane;
    private JPanel showWord;
    private JPanel showSelect_d;
    private JPanel showButton;
    private JLabel wordLabel;
    private ButtonGroup bg_d;
    private JRadioButton jrb1_d, jrb2_d;
    private JTextField textWord;
    private JButton button1;
    private JButton button2;
    private boolean isDelEn = true;

    public DelFrame(MyDictionaryDemo dicDemo) {
        setTitle("�༭(ɾ������)");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(530, 230, 300, 150);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0)); //��Ե����
        setContentPane(contentPane);

        showWord = new JPanel();
        showWord.setLayout(new FlowLayout());
        wordLabel = new JLabel("����:");
        textWord = new JTextField();
        textWord.setColumns(20);
        showWord.add(wordLabel);
        showWord.add(textWord);
        contentPane.add(showWord, BorderLayout.NORTH);

        showSelect_d = new JPanel();
        showSelect_d.setLayout(new FlowLayout());
        bg_d = new ButtonGroup();
        jrb1_d = new JRadioButton("ɾӢ��");
        jrb1_d.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                isDelEn = true;
            }
        });
        jrb2_d = new JRadioButton("ɾ����");
        jrb2_d.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                isDelEn = false;
            }
        });
        bg_d.add(jrb1_d);
        bg_d.add(jrb2_d);
        showSelect_d.add(jrb1_d);
        showSelect_d.add(jrb2_d);
        contentPane.add(showSelect_d, BorderLayout.CENTER);

        showButton = new JPanel();
        showButton.setLayout(new BorderLayout(0, 0));
        button1 = new JButton("ȡ��");
        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
        button2 = new JButton("ɾ��");
        button2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = textWord.getText();
                if (name.isEmpty()) {
                    do_button_actionPerformed1(e);
                    return;
                }
                if (!dicDemo.getMydictionary().deleteWord2(name, isDelEn)) {
                    do_button_actionPerformed2(e);
                    return;
                } else {
                    do_button_actionPerformed3(e);
                    return;
                }
            }
        });
        showButton.add(button1, BorderLayout.WEST);
        showButton.add(button2, BorderLayout.EAST);
        contentPane.add(showButton, BorderLayout.SOUTH);
    }
    //һЩ������ʾ
    protected void do_button_actionPerformed1(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "��������Ҫɾ���Ĵʣ�", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed2(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "��Ҫɾ���ĵ��ʲ����ڣ�", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed3(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "ɾ���ɹ���", null, JOptionPane.INFORMATION_MESSAGE);
    }

}

/* ���������������ʱ������ */
class AddWordToNoteFrame extends JFrame {

    private JPanel contentPane;
    private JPanel showWord;
    private JPanel showMeaning;
    private JPanel showButton;
    private JLabel wordLabel;
    private JLabel meaningLabel;
    private JTextField textWord;
    private JEditorPane textMeaning;
    private JButton button1;
    private JButton button2;
    private JButton button3;

    public AddWordToNoteFrame(MyDictionaryDemo dicDemo) {
        setTitle("���ʱ�");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(540, 240, 300, 400);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        showWord = new JPanel();
        showWord.setLayout(new FlowLayout());
        wordLabel = new JLabel("����:");
        textWord = new JTextField();
        textWord.setColumns(20);
        showWord.add(wordLabel);
        showWord.add(textWord);
        contentPane.add(showWord, BorderLayout.NORTH);

        showMeaning = new JPanel();
        showMeaning.setLayout(null);
        meaningLabel = new JLabel("����:");
        meaningLabel.setBounds(9, 40, 30, 20);
        textMeaning = new JEditorPane();
        textMeaning.setBounds(45, 40, 220, 190);

        showMeaning.add(meaningLabel);
        showMeaning.add(textMeaning);
        contentPane.add(showMeaning, BorderLayout.CENTER);

        showButton = new JPanel();
        showButton.setLayout(new BorderLayout(0, 0));
        button1 = new JButton("ȡ��");
        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
        //�����ò�ѯ����
        button2 = new JButton("��ѯ");
        button2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = textWord.getText();
                if (name.isEmpty()) {
                    do_button_actionPerformed1(e);
                    return;
                }
                if (dicDemo.getMydictionary().searchWordEntoCh2(name) == null) {
                    do_button_actionPerformed2(e);
                    return;
                } else {
                    textMeaning.setText(dicDemo.getMydictionary().searchWordEntoCh2(name));
                    return;
                }

            }
        });

        button3 = new JButton("���");
        button3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                //�����ļ�ѡ�񴰿�
                String name = textWord.getText();
                JFileChooser jfc = new JFileChooser();
                jfc.setDialogTitle("ѡ�����ʱ�");
                jfc.showSaveDialog(null);
                jfc.setVisible(true);
                String notefile = jfc.getSelectedFile().getAbsolutePath();
                if (name.isEmpty()) {
                    do_button_actionPerformed1(e);
                    return;
                }
                if (!dicDemo.getMydictionary().addWordTonotebook2(name, notefile)) {
                    do_button_actionPerformed2(e);
                    return;
                } else {
                    do_button_actionPerformed3(e);
                    return;
                }
            }
        });
        showButton.add(button1, BorderLayout.WEST);
        showButton.add(button2, BorderLayout.CENTER);
        showButton.add(button3, BorderLayout.EAST);
        contentPane.add(showButton, BorderLayout.SOUTH);
    }
    //һЩ������ʾ
    protected void do_button_actionPerformed1(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "������Ҫ�޸ĵĵ��ʣ�", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed2(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "Ҫ��ӵĵ��ʲ����ڣ�", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed3(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "��ӳɹ���", null, JOptionPane.INFORMATION_MESSAGE);
    }
}

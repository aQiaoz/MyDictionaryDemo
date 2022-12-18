import java.awt.*;//导入awt包
import java.awt.event.*; //导入awt.event包
import javax.swing.*;//导入swing包
import javax.swing.border.*;//导入swing.border包
import javax.swing.filechooser.*;//导入swing.filechooser包

/* 
 * 主界面是JFrame的子类，实现了ActionListener接口
 */
public class MyDictionaryDemo extends JFrame implements ActionListener {
    private static final long serialVersionUID = 776572726716394096L;// 序列化
    private JMenuBar menuBar; // 菜单栏
    private JMenu fileMenu, editMenu, toolMenu; // 文件菜单，编辑菜单，工具菜单
    private JPanel showDicName; // 显示导入词库名
    private JTextField dicDisplay; // 显示词库文本框
    private JPanel showSelect; // 显示英汉互译的选择按钮
    private JPanel showSeek; // 显示查询
    private JPanel showButton; // 显示释义
    private JTextArea wordSeek; // 查询输入框
    private ButtonGroup bg; // 单选按钮
    private JRadioButton jrb1, jrb2; // 点按钮
    private JEditorPane showText; // 释义显示面板
    private JButton butt; // 查询按钮

    private MyDictionary myDictionary = new MyDictionary(); // 词典类
    private String dicfileName; // 导入词典名
    private boolean isEnToCh = true; // 是否是英译汉的布尔变量，记录使用者的选择
    private boolean isImport = false; // 是否导入词库的布尔变量，记录使用者导入情况

    /* 主方法 */
    public static void main(String[] args) {
        MyDictionaryDemo frame = new MyDictionaryDemo();
        frame.setVisible(true);
    }

    /* 设计初始面板 */
    public MyDictionaryDemo() {
        setTitle("英汉双译词典");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // JPanel panel = new JPanel();
        // panel.setSize(400, 500);
        // panel.setVisible(true);
        // panel.setOpaque(false);
        // add(panel);

        // 顶层容器
        JPanel panelTop = new JPanel();
        panelTop.setOpaque(false);// 设置透明
        panelTop = (JPanel) getContentPane();// 设置为contentPane
        panelTop.setBorder(new EmptyBorder(5, 5, 5, 5));

        setBounds(500, 200, 400, 500);
        setVisible(true);
        panelTop.setLayout(null);

        setJMenuBar(createMenuBar()); // 添加菜单栏
        panelTop.add(creatShowDicName());// 添加显示导入词库名
        panelTop.add(creatShowSelect());// 选择中译英还是英译中
        panelTop.add(creatShowSeek());// 添加查询窗口
        panelTop.add(creatShowButton()); // 添加查询按钮
        panelTop.add(creatShowText()); // 添加释义窗口

    }

    /* 设计菜单栏，可以通过键盘实现选择，按住Alt＋提示即可 */
    private JMenuBar createMenuBar() {
        menuBar = new JMenuBar();
        fileMenu = new JMenu("文件(F)");
        fileMenu.setMnemonic(KeyEvent.VK_F);

        createOneMenuItem("导入词库(O)", KeyEvent.VK_O, fileMenu);
        createOneMenuItem("保存词库(S)", KeyEvent.VK_S, fileMenu);
        fileMenu.addSeparator();
        createOneMenuItem("退出(Q)", KeyEvent.VK_Q, fileMenu);
        menuBar.add(fileMenu);

        editMenu = new JMenu("编辑(E)");
        editMenu.setMnemonic(KeyEvent.VK_E);
        createOneMenuItem("添加单词(A)", KeyEvent.VK_A, editMenu);
        createOneMenuItem("修改单词(M)", KeyEvent.VK_M, editMenu);
        createOneMenuItem("删除单词(D)", KeyEvent.VK_D, editMenu);
        menuBar.add(editMenu);

        toolMenu = new JMenu("工具(T)");
        toolMenu.setMnemonic(KeyEvent.VK_Q);
        createOneMenuItem("导入单词到生词库(N)", KeyEvent.VK_N, toolMenu);
        menuBar.add(toolMenu);

        return menuBar;
    }

    /* 设置单个菜单，添加事件触发器 */
    private JMenuItem createOneMenuItem(String lable, int mnemonic, JMenu menu) {
        JMenuItem menuItem = new JMenuItem(lable);
        menuItem.setMnemonic(mnemonic);
        menuItem.addActionListener(this);
        menu.add(menuItem);
        return menuItem;
    }

    /* 设置显示导入词库名的面板 */
    private JPanel creatShowDicName() {
        showDicName = new JPanel();
        dicDisplay = new JTextField();
        dicDisplay.setEditable(false);
        dicDisplay.setText("还未导入词库");
        showDicName.add(dicDisplay);
        showDicName.setBounds(5, 5, 375, 30);
        return showDicName;

    }

    /* 设置英译中选项面板 */
    private JPanel creatShowSelect() {
        showSelect = new JPanel();
        bg = new ButtonGroup();
        jrb1 = new JRadioButton("英译中");
        jrb2 = new JRadioButton("中译英");
        jrb1.addActionListener(this);
        jrb2.addActionListener(this);
        bg.add(jrb1);
        bg.add(jrb2);
        showSelect.add(jrb1);
        showSelect.add(jrb2);
        showSelect.setBounds(5, 35, 375, 50);
        return showSelect;
    }

    /* 设置查询输入面板 */
    private JPanel creatShowSeek() {
        showSeek = new JPanel();
        wordSeek = new JTextArea();
        wordSeek.setColumns(20);
        showSeek.add(wordSeek);
        showSeek.setBounds(5, 85, 375, 50);

        return showSeek;
    }

    /* 设置查询按钮面板 */
    private JPanel creatShowButton() {
        showButton = new JPanel();
        butt = new JButton("查询");
        butt.addActionListener(this);
        showButton.add(butt);
        showButton.setBounds(5, 135, 375, 50);

        return showButton;
    }

    /* 设置释义显示面板 */
    private JEditorPane creatShowText() {
        showText = new JEditorPane();
        showText.setContentType("text/html");
        showText.setEditable(false);
        showText.setBounds(5, 185, 375, 220);

        return showText;
    }

    /* 响应按钮 */
    @Override
    public void actionPerformed(ActionEvent e) {
        if ("导入词库(O)".equals(e.getActionCommand())) {
            dicfileName = new String(); // 初始化导入词库
            // 设置文件选择窗口
            JFileChooser jfc = new JFileChooser();
            FileNameExtensionFilter filter = new FileNameExtensionFilter("txt", "txt");
            jfc.setDialogTitle("请选择文件");
            jfc.setFileFilter(filter);
            int ret = jfc.showOpenDialog(null);
            if (ret != JFileChooser.APPROVE_OPTION) {
                return;
            }
            dicfileName = jfc.getSelectedFile().getAbsolutePath();
            // 调用MyDictionary类的方法导入词库txt文件到map
            myDictionary.FileToDict(dicfileName);
            JOptionPane.showMessageDialog(this, "已成功导入", null, JOptionPane.INFORMATION_MESSAGE);
            isImport = true;
            dicDisplay.setText(dicfileName.substring(dicfileName.lastIndexOf("\\") + 1, dicfileName.lastIndexOf(".")));// 去除不必要字符显示出来
        }
        if ("保存词库(S)".equals(e.getActionCommand())) {
            // 设置文件选择窗口
            JFileChooser jfc = new JFileChooser();
            jfc.setDialogTitle("另存为");
            jfc.showSaveDialog(null);
            jfc.setVisible(true);
            String file = jfc.getSelectedFile().getAbsolutePath();
            // 调用MyDictionary的方法导出map里的数据到txt文件
            myDictionary.DictToFile(file);
            JOptionPane.showMessageDialog(this, "已成功保存", null, JOptionPane.INFORMATION_MESSAGE);
        }
        if ("退出(Q)".equals(e.getActionCommand())) {
            System.exit(0);
        }
        if ("添加单词(A)".equals(e.getActionCommand())) {
            // 弹出新的窗口AddFrame
            new AddFrame(this).setVisible(true);
        }
        if ("修改单词(M)".equals(e.getActionCommand())) {
            // 弹出新的窗口ModFrame
            new ModFrame(this).setVisible(true);
        }
        if ("删除单词(D)".equals(e.getActionCommand())) {
            // 弹出新的窗口DelFrame
            new DelFrame(this).setVisible(true);
        }
        if ("导入单词到生词库(N)".equals(e.getActionCommand())) {
            // 弹出新的窗口AddWordToNoteFrame
            new AddWordToNoteFrame(this).setVisible(true);
        }
        if ("英译中".equals(e.getActionCommand())) {
            // 设置bool变量
            isEnToCh = true;
        }
        if ("中译英".equals(e.getActionCommand())) {
            isEnToCh = false;
        }
        if ("查询".equals(e.getActionCommand())) {
            String text = wordSeek.getText();
            // 一些错误处理
            if (isImport == false) {
                // 如果用户未导入则提示用户
                JOptionPane.showMessageDialog(this, "还未导入词库！", null, JOptionPane.WARNING_MESSAGE);
                return;
            }
            if (text.isEmpty()) {
                // 如果用户输入为空则提示用户
                JOptionPane.showMessageDialog(this, "请输入要查询的单词！", null, JOptionPane.WARNING_MESSAGE);
                return;
            }
            if (isEnToCh) {
                if (myDictionary.searchWordEntoCh2(text) == null) {
                    JOptionPane.showMessageDialog(this, "要查询的单词不存在！", null, JOptionPane.WARNING_MESSAGE);
                    showText.setText("");
                    return;
                } else
                    showText.setText(myDictionary.searchWordEntoCh2(text));
            } else {
                if (myDictionary.searchWordChtoEn2(text) == null) {
                    JOptionPane.showMessageDialog(this, "要查询的中文不存在！", null, JOptionPane.WARNING_MESSAGE);
                    showText.setText("");
                    return;
                } else
                    // 最终在文本框显示释义，使用了MyDictionary类的searchWordChtoEn2方法
                    showText.setText(myDictionary.searchWordChtoEn2(text));
            }
        }
    }
    //返回导入词库名
    public String getfileName() {
        return dicfileName;
    }
    //返回MyDictionary类
    public MyDictionary getMydictionary() {
        return myDictionary;
    }
}

/* 设计添加单词的面板 */
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
        setTitle("编辑(添加单词)");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(510, 210, 300, 400);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));//边缘排版
        setContentPane(contentPane);

        showWord = new JPanel();
        showWord.setLayout(new FlowLayout());
        wordLabel = new JLabel("单词:");
        textWord = new JTextField();
        textWord.setColumns(20);
        showWord.add(wordLabel);
        showWord.add(textWord);
        contentPane.add(showWord, BorderLayout.NORTH);

        showMeaning = new JPanel();
        showMeaning.setLayout(null);
        meaningLabel = new JLabel("释义:");
        meaningLabel.setBounds(9, 40, 30, 20);
        textMeaning = new JEditorPane();
        textMeaning.setBounds(45, 40, 220, 190);

        showMeaning.add(meaningLabel);
        showMeaning.add(textMeaning);
        contentPane.add(showMeaning, BorderLayout.CENTER);

        showButton = new JPanel();
        showButton.setLayout(new BorderLayout(0, 0));
        button1 = new JButton("取消");
        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
        button2 = new JButton("添加");
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

    //一些错误提示
    protected void do_button_actionPerformed1(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "请输入需要添加的单词！", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed2(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "添加的单词存在！", null, JOptionPane.INFORMATION_MESSAGE);
    }

    protected void do_button_actionPerformed3(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "成功添加！", null, JOptionPane.WARNING_MESSAGE);
    }

}

/* 设计修改单词的面板 */
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
        setTitle("编辑(修改单词)");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(520, 220, 300, 400);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));//边缘布局
        setContentPane(contentPane);

        showWord = new JPanel();
        showWord.setLayout(new FlowLayout());
        wordLabel = new JLabel("单词:");
        textWord = new JTextField();
        textWord.setColumns(20);
        showWord.add(wordLabel);
        showWord.add(textWord);
        contentPane.add(showWord, BorderLayout.NORTH);

        showMeaning = new JPanel();
        showMeaning.setLayout(null);
        meaningLabel = new JLabel("释义:");
        meaningLabel.setBounds(9, 40, 30, 20);
        textMeaning = new JEditorPane();
        textMeaning.setBounds(45, 40, 220, 190);

        showMeaning.add(meaningLabel);
        showMeaning.add(textMeaning);
        contentPane.add(showMeaning, BorderLayout.CENTER);

        showButton = new JPanel();
        showButton.setLayout(new BorderLayout(0, 0));
        button1 = new JButton("取消");
        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });

        button2 = new JButton("查询");
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

        button3 = new JButton("确定");
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
    //一些报错提示
    protected void do_button_actionPerformed1(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "请输入要修改的单词！", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed2(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "要修改的单词不存在！", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed3(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "修改成功！", null, JOptionPane.WARNING_MESSAGE);
    }

}

/* 设计删除单词的面板 */
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
        setTitle("编辑(删除单词)");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(530, 230, 300, 150);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0)); //边缘布局
        setContentPane(contentPane);

        showWord = new JPanel();
        showWord.setLayout(new FlowLayout());
        wordLabel = new JLabel("单词:");
        textWord = new JTextField();
        textWord.setColumns(20);
        showWord.add(wordLabel);
        showWord.add(textWord);
        contentPane.add(showWord, BorderLayout.NORTH);

        showSelect_d = new JPanel();
        showSelect_d.setLayout(new FlowLayout());
        bg_d = new ButtonGroup();
        jrb1_d = new JRadioButton("删英文");
        jrb1_d.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                isDelEn = true;
            }
        });
        jrb2_d = new JRadioButton("删中文");
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
        button1 = new JButton("取消");
        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
        button2 = new JButton("删除");
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
    //一些报错提示
    protected void do_button_actionPerformed1(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "请输入需要删除的词！", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed2(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "需要删除的单词不存在！", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed3(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "删除成功！", null, JOptionPane.INFORMATION_MESSAGE);
    }

}

/* 设计添加神祠到生词本的面板 */
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
        setTitle("生词本");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(540, 240, 300, 400);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        showWord = new JPanel();
        showWord.setLayout(new FlowLayout());
        wordLabel = new JLabel("单词:");
        textWord = new JTextField();
        textWord.setColumns(20);
        showWord.add(wordLabel);
        showWord.add(textWord);
        contentPane.add(showWord, BorderLayout.NORTH);

        showMeaning = new JPanel();
        showMeaning.setLayout(null);
        meaningLabel = new JLabel("释义:");
        meaningLabel.setBounds(9, 40, 30, 20);
        textMeaning = new JEditorPane();
        textMeaning.setBounds(45, 40, 220, 190);

        showMeaning.add(meaningLabel);
        showMeaning.add(textMeaning);
        contentPane.add(showMeaning, BorderLayout.CENTER);

        showButton = new JPanel();
        showButton.setLayout(new BorderLayout(0, 0));
        button1 = new JButton("取消");
        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
        //仍设置查询功能
        button2 = new JButton("查询");
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

        button3 = new JButton("添加");
        button3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                //设置文件选择窗口
                String name = textWord.getText();
                JFileChooser jfc = new JFileChooser();
                jfc.setDialogTitle("选择生词本");
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
    //一些报错提示
    protected void do_button_actionPerformed1(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "请输入要修改的单词！", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed2(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "要添加的单词不存在！", null, JOptionPane.WARNING_MESSAGE);
    }

    protected void do_button_actionPerformed3(ActionEvent e) {
        JOptionPane.showMessageDialog(this, "添加成功！", null, JOptionPane.INFORMATION_MESSAGE);
    }
}

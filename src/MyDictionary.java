import java.io.*;
import java.util.*;

/* 
 * �����ӿڣ�������չ�̳�
 */
interface dictionary {
    void FileToDict(String filename); // ���뷽������txt�ļ����뵽Map���ݽṹ

    void addWord();// ��ӵ���

    void modifyWord();// �޸ĵ���

    void deleteWord();// ɾ������

    void searchWordEntoCh();// Ӣ��������

    void searchWordChtoEn();// ����Ӣ����

    void addWordTonotebook(String filename);// ��ӵ��ʵ����ʿ�

    void DictToFile(String filename); // ������������Map���ݽṹ������txt�ļ�

    int getsize(); // ���ص���������ʱû�õ�

    void output();// ��ʾ����
}

public class MyDictionary implements dictionary {
    private static Map<String, String> dict = null; // ����Ҫ��Map�ṹ����������һ��һ�����ʣ��洢���ʺͶ�Ӧ�����壬������Ѱ
    private static int size = 0;

    // ���뷽������txt�ļ����뵽Map���ݽṹ
    @Override
    public void FileToDict(String filename) {
        String s = null;
        String[] ss = null;
        dict = new HashMap<String, String>();
        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename)); // ʹ��BufferedReader�ַ�����ȡ�����ļ�
            while ((s = reader.readLine()) != null && s != "") { // txt�ļ���һ��һ��д��ȥ�ģ���ȡ��ʽҲ��һ��һ�ж�
                ss = s.split(" ");
                dict.put(ss[0], ss[1]);
                size++;
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // �ʿ����е��ʼ��������ʾ
    @Override
    public void output() {
        for (String key : dict.keySet()) {
            System.out.println(key + ":" + dict.get(key));
        }
    }

    // ��ӵ��ʷ���1�����ڱ�����������cmd������ʵ��
    @Override
    public void addWord() {
        System.out.println("�����뵥������:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        String meaning = null;
        if (dict.containsKey(name)) {
            System.out.println("��������Ѵ��ڣ�������:");
        } else {
            System.out.println("������������ʵ�������˼:");
            meaning = scanner.next();
            dict.put(name, meaning);
            System.out.println("��ӳɹ�!");

        }
    }

    // ��ӵ��ʷ���2������MyDictionaryDemo.java�����ͼ�ν�����ʾ
    public boolean addWord2(String name, String meaning) {
        if (dict.containsKey(name)) {
            return false;
        } else {
            dict.put(name, meaning);
            return true;
        }
    }

    // �޸ĵ��ʷ���1�����ڱ�����������cmd������ʵ��
    @Override
    public void modifyWord() {
        System.out.println("��������Ҫ�޸���˼�ĵ���:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        String meaning = null;
        if (!dict.containsKey(name)) {
            System.out.println("��Ҫ�޸���˼�ĵ��ʲ�����,������:");
        } else {
            System.out.println(name + "�޸�ǰ����˼��:" + dict.get(name));
            System.out.println("�������޸ĺ����˼");
            meaning = scanner.next();
            dict.put(name, meaning);
            System.out.println("�޸ĳɹ�!");
        }
    }

    // �޸ĵ��ʷ���2������MyDictionaryDemo.java�����ͼ�ν�����ʾ
    public boolean modifyWord2(String name, String meaning) {
        if (!dict.containsKey(name)) {
            return false;
        } else {
            dict.put(name, meaning);
            return true;
        }

    }

    // ɾ�����ʷ���1�����ڱ�����������cmd������ʵ��
    @Override
    public void deleteWord() {
        System.out.println("��������Ҫɾ���ĵ���:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        if (dict.remove(name) != null)
            System.out.println("ɾ���ɹ�!");
        else
            System.out.println("��Ҫɾ���ĵ��ʲ�����,������!");
    }

    // ɾ�����ʷ���2������MyDictionaryDemo.java�����ͼ�ν�����ʾ
    public boolean deleteWord2(String name, boolean bool) {
        boolean i = false;
        if (bool) {
            if (dict.remove(name) != null)
                return true;
            else
                return false;
        } else {
            for (String key : dict.keySet()) {
                if (dict.get(key).equals(name)) {
                    dict.remove(key);
                    i = true;
                }
            }
            return i == true ? true : false;
        }

    }

    // Ӣ�����������ʷ���1�����ڱ�����������cmd������ʵ��
    @Override
    public void searchWordEntoCh() {
        // System.out.println("��������Ҫ��ѯ��˼��Ӣ�ĵ���:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        if (!dict.containsKey(name)) {
            System.out.println("��Ҫ��ѯ��Ӣ�ĵ��ʲ�����,������!");
        } else {
            String meaning = dict.get(name);
            System.out.println(name + "�����ķ�����: " + meaning);
        }

    }

    // Ӣ�����������ʷ���2������MyDictionaryDemo.java�����ͼ�ν�����ʾ
    public String searchWordEntoCh2(String name) {
        return dict.get(name);

    }

    // ����Ӣ�������ʷ���1�����ڱ�����������cmd������ʵ��
    @Override
    public void searchWordChtoEn() {
        StringBuilder sb = new StringBuilder();
        System.out.println("��������Ҫ��ѯӢ�ķ��������:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        if (!dict.containsValue(name)) {
            System.out.println("��Ҫ��ѯӢ�ķ�������Ĳ�����,������!");
        } else {
            // ��value��keyֵ���ֲ��������
            for (String key : dict.keySet()) {// ����ÿһ��keyֵ�������Ӧ��value�Ƿ���ϴ��Ƚϵ�valueֵ
                if (dict.get(key).equals(name)) {
                    sb.append(key).append(" ");
                }
            }
            System.out.println(name + "��Ӣ�ķ�����: " + sb.toString());
        }
    }

    // ����Ӣ�������ʷ���2������MyDictionaryDemo.java�����ͼ�ν�����ʾ
    public String searchWordChtoEn2(String name) {
        StringBuilder sb = new StringBuilder();
        if (!dict.containsValue(name)) {
            return null;
        } else {
            for (String key : dict.keySet()) {
                if (dict.get(key).equals(name)) {
                    sb.append(key).append(" ");
                }
            }
            return sb.toString();
        }
    }

    // ��ӵ��ʵ����ʿⷽ��1�����ڱ�����������cmd������ʵ��
    @Override
    public void addWordTonotebook(String filename) {
        System.out.println("��������Ҫ��ӵ����ʱ��ĵ���:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        if (!dict.containsKey(name)) {
            System.out.println("��Ҫ��ӵĵ��ʲ�����,������!");
        } else {
            try {
                File fnote = new File(filename);
                BufferedWriter writer = new BufferedWriter(new FileWriter(fnote, true));
                writer.write(name + " " + dict.get(name));
                writer.newLine();
                writer.flush();
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            System.out.println("�Ѿ��ɹ���ӣ�");
        }
    }

    // ��ӵ��ʵ����ʿⷽ��2������MyDictionaryDemo.java�����ͼ�ν�����ʾ
    public boolean addWordTonotebook2(String name, String filename) {
        if (!dict.containsKey(name)) {
            return false;
        } else {
            try {
                File fnote = new File(filename);
                BufferedWriter writer = new BufferedWriter(new FileWriter(fnote, true));
                writer.write(name + " " + dict.get(name));
                writer.newLine();
                writer.flush();
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return true;
        }
    }

    // ������������Map���ݽṹ������txt�ļ�
    @Override
    public void DictToFile(String filename) {
        try {
            File f = new File(filename);
            if (f.delete()) {
                BufferedWriter writer = new BufferedWriter(new FileWriter(f, false));
                for (String key : dict.keySet()) {
                    writer.write(key + " " + dict.get(key));
                    writer.newLine();
                    writer.flush();
                }
                writer.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public int getsize() {
        return size;
    }

    /*
     * ������cmd�������
     */
    public static void main(String[] args) {
        String fileName = "dictest.txt";
        String notebookName = "notebook.txt";
        MyDictionary myDictionary = new MyDictionary();
        myDictionary.FileToDict(fileName);
        boolean t = true;
        while (t) {
            System.out.println("������������������ӭʹ����Ӣ�Ĵʵ�ϵͳ����������������");
            System.out.println("1.��ѯӢ�ĵ��ʷ���");
            System.out.println("2.��ѯ���ĵ��ʷ���");
            System.out.println("3.��ӵ���");
            System.out.println("4.�޸ĵ�����˼");
            System.out.println("5.ɾ������");
            System.out.println("6.������������ʿ�");
            System.out.println("7.�˳�ϵͳ");
            System.out.println("������������������������������������������������������������������������\n");
            System.out.println("���������ѡ��");

            Scanner scanner = new Scanner(System.in);
            int i = scanner.nextInt();
            switch (i) {
                case 1:
                    myDictionary.searchWordEntoCh();
                    break;
                case 2:
                    myDictionary.searchWordChtoEn();
                    break;
                case 3:
                    myDictionary.addWord();
                    break;
                case 4:
                    myDictionary.modifyWord();
                    break;
                case 5:
                    myDictionary.deleteWord();
                    break;
                case 6:
                    myDictionary.addWordTonotebook(notebookName);
                    ;
                    break;
                case 7:
                    System.out.println("ллʹ��");
                    t = false;
            }
        }
        myDictionary.DictToFile(fileName);

    }
}
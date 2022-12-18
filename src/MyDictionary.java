import java.io.*;
import java.util.*;

/* 
 * 基础接口，方便拓展继承
 */
interface dictionary {
    void FileToDict(String filename); // 导入方法，将txt文件导入到Map数据结构

    void addWord();// 添加单词

    void modifyWord();// 修改单词

    void deleteWord();// 删除单词

    void searchWordEntoCh();// 英译中搜索

    void searchWordChtoEn();// 中译英搜索

    void addWordTonotebook(String filename);// 添加单词到生词库

    void DictToFile(String filename); // 导出方法，将Map数据结构导出到txt文件

    int getsize(); // 返回单词数，暂时没用到

    void output();// 显示方法
}

public class MyDictionary implements dictionary {
    private static Map<String, String> dict = null; // 最重要的Map结构，利用了它一对一的性质，存储单词和对应的释义，方便搜寻
    private static int size = 0;

    // 导入方法，将txt文件导入到Map数据结构
    @Override
    public void FileToDict(String filename) {
        String s = null;
        String[] ss = null;
        dict = new HashMap<String, String>();
        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename)); // 使用BufferedReader字符流读取可视文件
            while ((s = reader.readLine()) != null && s != "") { // txt文件是一行一行写进去的，读取方式也是一行一行读
                ss = s.split(" ");
                dict.put(ss[0], ss[1]);
                size++;
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 词库所有单词及释义的显示
    @Override
    public void output() {
        for (String key : dict.keySet()) {
            System.out.println(key + ":" + dict.get(key));
        }
    }

    // 添加单词方法1，用于本程序主方法cmd交互的实现
    @Override
    public void addWord() {
        System.out.println("请输入单词名称:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        String meaning = null;
        if (dict.containsKey(name)) {
            System.out.println("这个单词已存在，请重试:");
        } else {
            System.out.println("请输入这个单词的中文意思:");
            meaning = scanner.next();
            dict.put(name, meaning);
            System.out.println("添加成功!");

        }
    }

    // 添加单词方法2，用于MyDictionaryDemo.java程序的图形界面显示
    public boolean addWord2(String name, String meaning) {
        if (dict.containsKey(name)) {
            return false;
        } else {
            dict.put(name, meaning);
            return true;
        }
    }

    // 修改单词方法1，用于本程序主方法cmd交互的实现
    @Override
    public void modifyWord() {
        System.out.println("请输入您要修改意思的单词:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        String meaning = null;
        if (!dict.containsKey(name)) {
            System.out.println("您要修改意思的单词不存在,请重试:");
        } else {
            System.out.println(name + "修改前的意思是:" + dict.get(name));
            System.out.println("请输入修改后的意思");
            meaning = scanner.next();
            dict.put(name, meaning);
            System.out.println("修改成功!");
        }
    }

    // 修改单词方法2，用于MyDictionaryDemo.java程序的图形界面显示
    public boolean modifyWord2(String name, String meaning) {
        if (!dict.containsKey(name)) {
            return false;
        } else {
            dict.put(name, meaning);
            return true;
        }

    }

    // 删除单词方法1，用于本程序主方法cmd交互的实现
    @Override
    public void deleteWord() {
        System.out.println("请输入您要删除的单词:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        if (dict.remove(name) != null)
            System.out.println("删除成功!");
        else
            System.out.println("您要删除的单词不存在,请重试!");
    }

    // 删除单词方法2，用于MyDictionaryDemo.java程序的图形界面显示
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

    // 英译中搜索单词方法1，用于本程序主方法cmd交互的实现
    @Override
    public void searchWordEntoCh() {
        // System.out.println("请输入您要查询意思的英文单词:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        if (!dict.containsKey(name)) {
            System.out.println("您要查询的英文单词不存在,请重试!");
        } else {
            String meaning = dict.get(name);
            System.out.println(name + "的中文翻译是: " + meaning);
        }

    }

    // 英译中搜索单词方法2，用于MyDictionaryDemo.java程序的图形界面显示
    public String searchWordEntoCh2(String name) {
        return dict.get(name);

    }

    // 中译英搜索单词方法1，用于本程序主方法cmd交互的实现
    @Override
    public void searchWordChtoEn() {
        StringBuilder sb = new StringBuilder();
        System.out.println("请输入您要查询英文翻译的中文:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        if (!dict.containsValue(name)) {
            System.out.println("您要查询英文翻译的中文不存在,请重试!");
        } else {
            // 由value搜key值，局部方法设计
            for (String key : dict.keySet()) {// 遍历每一个key值，看其对应的value是否符合待比较的value值
                if (dict.get(key).equals(name)) {
                    sb.append(key).append(" ");
                }
            }
            System.out.println(name + "的英文翻译是: " + sb.toString());
        }
    }

    // 中译英搜索单词方法2，用于MyDictionaryDemo.java程序的图形界面显示
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

    // 添加单词到生词库方法1，用于本程序主方法cmd交互的实现
    @Override
    public void addWordTonotebook(String filename) {
        System.out.println("请输入您要添加到生词本的单词:");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        if (!dict.containsKey(name)) {
            System.out.println("您要添加的单词不存在,请重试!");
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
            System.out.println("已经成功添加！");
        }
    }

    // 添加单词到生词库方法2，用于MyDictionaryDemo.java程序的图形界面显示
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

    // 导出方法，将Map数据结构导出到txt文件
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
     * 主方法cmd交互设计
     */
    public static void main(String[] args) {
        String fileName = "dictest.txt";
        String notebookName = "notebook.txt";
        MyDictionary myDictionary = new MyDictionary();
        myDictionary.FileToDict(fileName);
        boolean t = true;
        while (t) {
            System.out.println("————————欢迎使用中英文词典系统————————");
            System.out.println("1.查询英文单词翻译");
            System.out.println("2.查询中文单词翻译");
            System.out.println("3.添加单词");
            System.out.println("4.修改单词意思");
            System.out.println("5.删除单词");
            System.out.println("6.添加生词至生词库");
            System.out.println("7.退出系统");
            System.out.println("————————————————————————————————————\n");
            System.out.println("请输入你的选择：");

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
                    System.out.println("谢谢使用");
                    t = false;
            }
        }
        myDictionary.DictToFile(fileName);

    }
}
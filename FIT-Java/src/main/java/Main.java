import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        TextStatistics stat = new TextStatistics();
        stat.addWord("abc");
        stat.addWord("abcd");
        stat.addWord("abcd");
        stat.addWord("abcde");
    }
}

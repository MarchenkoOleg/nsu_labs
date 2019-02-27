import java.util.HashMap;

public class TextStatistics {
    private HashMap<String, WordStatistics> words;
    private int count;

    public TextStatistics() {
        words = new HashMap<>();
    }

    public void addWord(String word) {
        count++;
        if (words.containsKey(word))
            words.put(word, new WordStatistics(word, words.get(word).getCount() + 1));
        else
            words.put(word, new WordStatistics(word, 1));
    }

    public HashMap<String, WordStatistics> getWords() {
        return words;
    }

    public int getCount() {
        return count;
    }
}

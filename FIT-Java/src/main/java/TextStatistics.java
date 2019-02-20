import java.util.HashMap;
import java.util.Map;

public class TextStatistics {
    private Map<String, WordStatistics> words;
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
}

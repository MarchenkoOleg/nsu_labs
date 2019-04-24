package ru.nsu.fit.group17209.marchenko;

import java.util.HashMap;
import java.util.Map;

public class TextStatistics {
    private HashMap<String, WordStatistics> words;
    private int count;

    public TextStatistics() {
        words = new HashMap<>();
    }

    public void addWord(String word) {
        count++;
        if (words.containsKey(word)) {
            words.put(word, words.get(word).increment());
            //words.put(word, new WordStatistics(word, words.get(word).getCount() + 1));
        } else {
            words.put(word, new WordStatistics(word, 1));
        }
    }

    public Map<String, WordStatistics> getWords() { return words; }

    public int getCount() { return count; }
}

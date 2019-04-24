package ru.nsu.fit.group17209.marchenko;

public class WordStatistics implements Comparable<WordStatistics> {
    private String word;
    private int count;

    public WordStatistics(String word, int count) {
        this.count = count;
        this.word = word;
    }

    public int getCount() {
        return count;
    }

    public String getWord() {
        return word;
    }

    public WordStatistics increment() {
        count++;
        return this;
    }

    @Override
    public int compareTo(WordStatistics o) {
        int result = Integer.compare(o.getCount(), getCount());
        if (result == 0) {
            return getWord().compareTo(o.getWord());
        } else {
            return result;
        }
    }

}

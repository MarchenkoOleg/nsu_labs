import java.util.Arrays;

public class Cell {

    private int pos_x;
    private int pos_y;
    private String state;
    private boolean mined;
    private int counter;

    private static final String[] states = new String[] {"closed", "flagged", "questioned"};

    public Cell(int x, int y, boolean mine) {
        pos_x = x;
        pos_y = y;
        mined = mine;
        state = "closed";
    }

    public void nextMark() {
        if(Arrays.asList(states).contains(state)) {
            int stateIndex = Arrays.asList(states).indexOf(state);
            state = states[(stateIndex + 1) % states.length];
        }
    }

    public void open() {
        if(state != "flagged") {
            state = "opened";
        }
    }

    public String getState() {return state;}

    public boolean isMined() {return mined;}

    public void setCounter(int c) {counter = c;}

    public int getCounter() {return counter;}

    public int getPos_x() {return pos_x;}

    public int getPos_y() {return pos_y;}

    public void setMine() {mined = true;}


}

package MinesweeperModel;

public class Cell {

    CellListeners listeners = new CellListeners();
    private int pos_x;
    private int pos_y;
    private CellState state;
    private boolean mined;
    private int counter;

    public Cell(int x, int y, boolean mine) {
        pos_x = x;
        pos_y = y;
        mined = mine;
        state = CellState.CLOSED;
    }

    public void nextMark() {
        if(!state.isFinal()) {
            state = state.getNext();
            listeners.notifyCellUpdated(this);
        }
    }

    public boolean open() {
        if(state != CellState.FLAGGED) {
            state = CellState.OPENED;
            listeners.notifyCellUpdated(this);
            return true;
        }
        return false;
    }

    public CellState getState() {return state;}

    public boolean isMined() {return mined;}

    public void setCounter(int c) {counter = c;}

    public int getCounter() {return counter;}

    public int getPos_x() {return pos_x;}

    public int getPos_y() {return pos_y;}

    public void setMine() {
        mined = true;
    }

    public void addListener(Object obj) {
        listeners.add(obj);
    }

    public void clearListeners() {
        listeners.clear();
    }


}

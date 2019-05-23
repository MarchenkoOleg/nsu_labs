package MinesweeperModel;

public enum CellState {
    CLOSED (2),
    OPENED (-1),
    FLAGGED (3),
    QUESTIONED(0);
    ;
    private CellState(int nextOrdinal) {
        this.nextOrdinal = nextOrdinal;
    }
    private int nextOrdinal;

    public CellState getNext() {
        return (nextOrdinal >=0 ) ? values()[nextOrdinal] : null;
    }
    public boolean isFinal() {
        return (nextOrdinal < 0);
    }

}

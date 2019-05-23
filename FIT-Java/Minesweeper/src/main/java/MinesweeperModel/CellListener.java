package MinesweeperModel;

import java.util.ArrayList;
import java.util.Iterator;

public interface CellListener {
    void cellUpdated(Cell cell);
    void cellOpened(Cell cell);
    void cellFlagged(Cell cell);
    void cellQuestioned(Cell cell);
    void cellClosed(Cell cell);
}

class CellListeners<T extends CellListener> extends ArrayList<T> {
    public void notifyCellUpdated(Cell cell) {
        for (Iterator<T> it = iterator(); it.hasNext();)
            it.next().cellUpdated(cell);
    }
    public void notifyCellOpened(Cell cell) {
        for (Iterator<T> it = iterator(); it.hasNext();)
            it.next().cellOpened(cell);
    }
    public void notifyCellFlagged(Cell cell) {
        for (Iterator<T> it = iterator(); it.hasNext();)
            it.next().cellFlagged(cell);
    }
    public void notifyCellQuestioned(Cell cell) {
        for (Iterator<T> it = iterator(); it.hasNext();)
            it.next().cellQuestioned(cell);
    }
    public void notifyCellClosed(Cell cell) {
        for (Iterator<T> it = iterator(); it.hasNext();)
            it.next().cellClosed(cell);
    }
}


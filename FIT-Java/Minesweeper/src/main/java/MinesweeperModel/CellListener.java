package MinesweeperModel;

import java.util.ArrayList;
import java.util.Iterator;

public interface CellListener {
    void cellUpdated(Cell cell);
}

class CellListeners<T extends CellListener> extends ArrayList<T> {
    public void notifyCellUpdated(Cell cell) {
        for (Iterator<T> it = iterator(); it.hasNext();)
            it.next().cellUpdated(cell);
    }
}


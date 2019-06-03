package MinesweeperModel;

import javax.swing.*;
import java.util.ArrayList;
import java.util.Iterator;

public interface TimerListener {
    void TimerUpdated();
}

class TimerListeners<T extends TimerListener> extends ArrayList<T> {
    public void notifyTimerUpdated() {
        for (Iterator<T> it = iterator(); it.hasNext();)
            it.next().TimerUpdated();
    }
}


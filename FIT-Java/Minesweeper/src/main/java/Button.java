import javax.swing.*;
import java.awt.*;

public class Button extends JButton {

    private Cell cell;
    private JButton button;
    private Controller controller;

    public Button(Cell c) {
        super();
        cell = c;
        button = new JButton("");
        button.setPreferredSize(new Dimension(50, 50));
        controller = new Controller(cell);
        button.addMouseListener(controller);
    }

    public void config(Color c, String txt) {
        button.setBackground(c);
        button.setText(txt);
    }

    public void config(Color c) {
        button.setBackground(c);
    }

    public void config(String txt) {
        button.setText(txt);
    }

    public JButton getButton() {
        return this.button;
    }

    public Cell getCell() {return cell;}
}

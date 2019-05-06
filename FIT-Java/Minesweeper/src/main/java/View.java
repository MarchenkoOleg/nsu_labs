import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class View extends JPanel {

    static private JFrame frame = new JFrame("Minesweeper");
    private JPanel view;
    private Model model;
    private Controller controller;
    private Button[][] field;

    public View(Model model, Controller controller) {

        frame.setContentPane(this);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setResizable(true);
        frame.setAlwaysOnTop(true);
        this.model = model;
        this.controller = controller;
        controller.setView(this);
        view = new JPanel();
        view.setLayout(new GridLayout(model.getHeight(), model.getWidth()));
        field = new Button[model.getHeight()][model.getWidth()];
        buildButtons();
        this.add(view, BorderLayout.SOUTH);
        frame.pack();

    }

    public void syncWithModel() {
        for (int i = 0; i < model.getHeight(); i++) {
            for (int j = 0; j < model.getWidth(); j++) {
                Cell cell = model.getCell(i, j);
                Button btn = field[i][j];

                if(model.isGameOver() && cell.isMined()) {
                    btn.config(Color.BLACK, "");
                }
                if(cell.getState() == "closed") {
                    btn.config("");
                } else if(cell.getState() == "opened") {
                    btn.config(Color.LIGHT_GRAY, "");
                    if(cell.getCounter() > 0) {
                        btn.config(Integer.toString(cell.getCounter()));
                    } else if(cell.isMined()) {
                        btn.config(Color.RED);
                    }
                } else if(cell.getState() == "flagged") {
                    btn.config("P");
                } else if(cell.getState() == "questioned") {
                    btn.config("?");
                }
            }
        }
    }

    private void buildButtons() {

        for (int i = 0; i < model.getHeight(); i++) {
            for (int j = 0; j < model.getWidth(); j++) {
                Cell cell = model.getCell(i, j);
                //System.out.println(cell.getState());
                Button button = new Button(cell);
                field[i][j] = button;
                this.view.add(button.getButton());
            }
        }


    }

    public void showWinMessage() {
        JOptionPane.showMessageDialog(frame, "Поздравляем, Вы победили!");
    }

    public void showGameOverMessage() {
        JOptionPane.showMessageDialog(frame, "Игра окончена, Вы проиграли!");
    }

}

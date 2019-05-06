import javax.swing.*;
import java.io.IOException;

public class App {
    public static void main(String[] argv) throws IOException {

        Model model = new Model();
        Controller controller = new Controller(model);
        View view = new View(model, controller);

    }
}

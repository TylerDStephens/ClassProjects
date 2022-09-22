import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
class ChatBox extends ChatBox2{
    public ChatBox() {
        f1.setTitle("Chatbox");
        f1.jt.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent ke) {
                if (ke.getKeyCode() == KeyEvent.VK_ENTER) {
                    String msg = f1.jt.getText();
                    f1.showLabel(msg);
                    f2.showLabel(msg);
                }
            }
        });
        f1.setVisible(true);
    }
}
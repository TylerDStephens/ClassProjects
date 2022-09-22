import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
class ChatBox2 extends ChatBoxWrappers{
    public ChatBox2() {
        f2.setTitle("Chatbox2");
        f2.jt.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent ke) {
                if (ke.getKeyCode() == KeyEvent.VK_ENTER) {
                    String msg = f2.jt.getText();
                    f2.showLabel(msg);
                    f1.showLabel(msg);
                }
            }
        });
       f2.setVisible(true);
    }
}
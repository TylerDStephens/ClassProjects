import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class FrameDesigner extends JFrame{
    JPanel jp;
    JTextField jt;
    JTextArea ta;
    JLabel l;
    public FrameDesigner() {
        //setTitle("Chatbox");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        jp = new JPanel();
        jp.setLayout(new GridLayout(2, 1));
        l = new JLabel();
        jp.add(l);
        jt = new JTextField();
        jp.add(jt);
        add(jp, BorderLayout.SOUTH);
        ta = new JTextArea();
        ta.setEditable(false);
        ta.setMargin(new Insets(7, 7, 7, 7));
        JScrollPane js = new JScrollPane(ta);
        add(js);
        addWindowListener(new WindowAdapter() {
            public void windowOpened(WindowEvent we) {
                jt.requestFocus();
            }
        });
        setSize(400, 400);
        setLocationRelativeTo(null);
        //setVisible(true);
    }
    public void showLabel(String text)
    {
        if(text.trim().isEmpty()) return;
        ta.append(text+"\n");
        jt.setText("");
        l.setText("");
    }
}
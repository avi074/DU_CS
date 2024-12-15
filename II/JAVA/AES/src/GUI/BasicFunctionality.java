package GUI;

import javax.swing.*;
import javax.swing.border.AbstractBorder;
import javax.swing.border.Border;
import javax.swing.border.MatteBorder;
import javax.swing.text.JTextComponent;
import java.awt.*;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.net.URL;

public interface BasicFunctionality extends SwingConstants {
    //Color
    Color Transparent = new Color(0, 0, 0, 0);

    //Borders
    Border Simple_border = new MatteBorder(0, 0, 2, 0, Color.black);

    @SuppressWarnings("serial")
	Border Round_border = new AbstractBorder() {
        @Override
        public void paintBorder(Component c, Graphics g, int x, int y, int width, int height) {
            Graphics2D g2 = (Graphics2D) g.create();
            g2.drawRoundRect(x, y, c.getWidth() - 1, c.getHeight() - 1, 20, 20);
            g2.dispose();
        }
    };

    Border Round_Title_border = new AbstractBorder() {
        @Override
        public void paintBorder(Component c, Graphics g, int x, int y, int width, int height) {
            Graphics2D g2 = (Graphics2D) g.create();
            g2.setColor(Color.BLUE);
            g2.drawRoundRect(x, y, c.getWidth() -1, c.getHeight() - 2, 30, 30);
            g2.dispose();
        }
    };

    Border Error_border = new MatteBorder(0, 0, 2, 0, Color.red);

    // resize the ImageIcon
    default ImageIcon resize(URL Path, Dimension d) {
        return new ImageIcon(new ImageIcon(Path).getImage().getScaledInstance(d.width, d.height, Image.SCALE_SMOOTH));
    }
    default ImageIcon resize(String Path, Dimension d) {
        return new ImageIcon(new ImageIcon(Path).getImage().getScaledInstance(d.width, d.height, Image.SCALE_SMOOTH));
    }

    default void Animation(Color enter, Color exit, JComponent c){
            c.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseEntered(MouseEvent e) {
                    c.setBackground(enter);
                }

                @Override
                public void mouseExited(MouseEvent e) {
                    c.setBackground(exit);
                }
            });
    }
    default void Animation(Color enter, Color exit, JComponent... c){
        for(JComponent o : c)
            this.Animation(enter,exit,o);
    }

    default void Placeholder(JTextComponent... obj){
    	for(JTextComponent c : obj) {
    		c.addFocusListener(new FocusListener() {
                @Override
                public void focusGained(FocusEvent e) {
                    if(c.getText().equals(c.getToolTipText())){
                        c.setText("");
                        c.setBorder(Simple_border);
                    }
                }

                @Override
                public void focusLost(FocusEvent e) {
                    if(c.getText().isBlank()){
                        c.setText(c.getToolTipText());
                        c.setBorder(Round_border);
                    }
                }
            });
    	}
    }

    default void setParameters(Color bg, Border border, JTextComponent... a) {
    	for(JTextComponent o : a) {
    		o.setBackground(bg);
    		o.setBorder(border);
    		o.setOpaque(false);
    		if(o.getText().isBlank()) {
                o.setText(o.getToolTipText());
            }
    	}
    }

    default void setParameters(Color bg, Border border,Font f, JComponent... a) {
        for(JComponent o : a) {
            o.setBackground(bg);
            o.setFont(f);
            o.setFocusable(true);
            o.setBorder(border);
        }
    }
    default void change(boolean b, JTextComponent ...c){
        for (JTextComponent o : c){
            o.setEnabled(b);
        }
    }
    default void change(boolean b, JComboBox<String> g, JComboBox<String> e,JTextComponent ...c){
        g.setEnabled(b);
        e.setEnabled(b);
        this.change(b,c);
    }
}
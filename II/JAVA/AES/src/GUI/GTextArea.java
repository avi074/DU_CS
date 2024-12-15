package GUI;

import java.awt.*;
import java.beans.BeanProperty;

public class GTextArea extends TextArea {

    private boolean wrap;

    public GTextArea() throws HeadlessException {

    }

    public GTextArea(String text) throws HeadlessException {
        super(text);
    }

    public GTextArea(int rows, int columns) throws HeadlessException {
        super(rows, columns);
    }

    public GTextArea(String text, int rows, int columns) throws HeadlessException {
        super(text, rows, columns);
    }

    public GTextArea(int scrollbars) throws HeadlessException {
        super("",0,0, scrollbars);
    }

    public void setWrapping(boolean wrap) {
        boolean old = this.wrap;
        this.wrap = wrap;
        firePropertyChange("lineWrap", old, wrap);
        firePropertyChange("wrapStyleWord", old, wrap);
    }
    public boolean isWrap(){
        return this.wrap;
    }
}

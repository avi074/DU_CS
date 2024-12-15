package Database;

import javax.swing.JTextField;
import javax.swing.JPasswordField;
import java.util.prefs.BackingStoreException;
import java.util.prefs.Preferences;

public class UserPref {
    private static final Preferences pref = Preferences.userRoot();

    public static void createPref(){
        try {
            if(!pref.nodeExists("AES")){
                pref.node("AES");
                pref.put("email","");
                pref.put("password","");
            }
        } catch (BackingStoreException e) {
            e.printStackTrace();
        }
    }

    public static void getPref(JTextField e, JPasswordField p){
        pref.node("AES");
        e.setText(pref.get("email",""));
        p.setText(pref.get("password",""));
    }
    public static void setPref(JTextField e, JPasswordField p){
        pref.node("AES");
        pref.put("email",e.getText());
        pref.put("password", String.valueOf(p.getPassword()));
    }
}

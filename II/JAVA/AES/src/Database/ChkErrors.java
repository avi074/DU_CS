package Database;

import GUI.BasicFunctionality;
import com.toedter.calendar.JDateChooser;
import javax.swing.*;
import javax.swing.text.JTextComponent;

public class ChkErrors implements BasicFunctionality {
    private static boolean err ;
    private static String msg = "Please fill the red fields properly !!!" ;

    public static boolean fieldError(JTextComponent... a){
        err = false;
        for (JTextComponent c: a) {
            if(c.getText().equals(c.getToolTipText()) || c.getText().isBlank()) {
                c.setBorder(Error_border);
                err = true;
            }

            if(c instanceof JPasswordField){
                if(((JPasswordField) c).getPassword().length < 8){
                    c.setToolTipText("Password must be at least of 8 characters !!!");
                    c.setBorder(Error_border);
                    msg += "\n" + c.getToolTipText();
                    err = true;
                }
            }
        }
        if(err)
            show();
        return err;
    }
    public static boolean regError(JComboBox<String> c, JComboBox<String> c1, JDateChooser d, JTextComponent...a){
       err = fieldError(a);
       if(c.getSelectedIndex() == 0){
           c.setBorder(Error_border);
           err = true;
           msg += "\n Please Choose your Gender !!!";
       }
       if(c1.getSelectedIndex() == 0) {
           c1.setBorder(Error_border);
           err = true;
           msg += "\n Please choose your category !!!";
       }
       if(d.getDateFormatString().equals("")){
           d.setBorder(Error_border);
           err = true;
           msg += "\n Please enter your Date of Birth !!!";
       }

       if(!a[5].getText().equals(a[6].getText())){
           a[5].setBorder(Error_border);
           a[6].setBorder(Error_border);
           err = true;
           msg += "\n Password & confirm password must be matched !!!";
       }
       if(err)
           show();
       return err;
    }
    public static boolean chkpercent(float per,String cllg, int index){
        String[] percent = DB.strArray(Colleges.get("percent","name = '"+cllg+"'"));
        boolean eligible = false;

        if(per >= Float.parseFloat(percent[index]))
           eligible = true;
        else
            JOptionPane.showMessageDialog(null, "Your percentage is " + per + "\nDemanding percent is " + percent[index] + "\n\nSo You are not eligible !!!", "NotEligible", JOptionPane.ERROR_MESSAGE);
        return eligible;
    }

    private static void show(){
        JOptionPane.showMessageDialog(null,msg,"Input Error",JOptionPane.ERROR_MESSAGE);
    }

    public static boolean Empty(JTextComponent ...c){
        boolean empty = false;
        for(JTextComponent o:c){
            if(o.getText().isBlank()){
               empty = true;
            }
        }
        return empty;
    }
}

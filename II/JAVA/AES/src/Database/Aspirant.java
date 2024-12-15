package Database;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Aspirant{

    private static String[] fields = {"`reg_no`", "`photo`", "`sign`", "`name`", "`f_name`", "`m_name`","`dob`", "`mob`","`email`", "`password`",
            "`sec_key`","`gen`", "`categ`", "`10_roll`", "`10_board`", "`10_percent`", "`12_roll`", "`12_board`",
            "`12_percent`","`12_subs`", "`12_subs_obt`", "`12_subs_total`", "`applied_colleges`", "`applied_courses`", "`applied_Date`" };

    public static String get(String field, String condition) {
        return DB.getField("aspirant",field,condition);
    }

    public static void setUser(int gen, int categ, String ...s){
        String f = fields[3];
        StringBuilder v = new StringBuilder("'" + s[0] + "'");

        for (byte i = 4; i <= 12; i++)
            f += "," + fields[i];
        for (byte i = 1; i < s.length; i++)
           v.append(",'").append(s[i]).append("'");

        v.append(", '").append(sec_key(s[4],s[5])).append("','").append(gen).append("','").append(categ).append("'");
        DB.setField("aspirant",f, v.toString());
    }

    public static String sec_key(String email, String pwd){
        char[] key = new char[8];
        for (byte i = 0; i < 8; i++){
            key[i] = (char) (i + email.charAt(i % pwd.length()));
        }
        return String.valueOf(key);
    }

    public static ResultSet getTable(String condition){
        return DB.getTable("aspirant",condition);
    }

    public static void setImage(File file, String field, String condition){
        String query = "UPDATE `aspirant` set `"+ field +"` = ? where " + condition;
        try(PreparedStatement pst = DB.connect().prepareStatement(query)){
            pst.setBinaryStream(1,new FileInputStream(file));
            pst.executeUpdate();
        } catch (SQLException | IOException e) {
            DB.ShowError(e);
        }
    }

    public static void Update(String field, String value,String condition){
        DB.update("aspirant",field,value,condition);
    }

    public static void delete(String condition){
        DB.delete("aspirant",condition);
    }

    public static String chkLogin(String email, String pwd){
        return DB.toStr(get("reg_no","email = '"+email+"' AND password = '"+ pwd+"'"));
    }

}

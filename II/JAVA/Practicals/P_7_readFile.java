import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class P_7_readFile {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the filepath with extension : ");
        chk_print(scan.nextLine());
        scan.close();
    }

    private static void chk_print(String path) {
        String str;
        try(Scanner file = new Scanner(new File(path)))
        {
            file.useDelimiter("\n");
            while(file.hasNextLine())
            {
                str = file.nextLine();
                if(str.startsWith("//"))
                    System.out.println(str);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
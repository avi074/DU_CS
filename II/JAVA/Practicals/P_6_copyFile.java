import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class P_6_copyFile {
    public static void main(String[] args) {
        byte[] data;

        if(args.length != 2)
            printSyntax();
        else
        {
            try (FileInputStream fin =new FileInputStream(args[0]);
                 FileOutputStream fout = new FileOutputStream(args[1]))
            {
                while (fin.available() != 0) {
                    data = fin.readAllBytes();
                    fout.write(data);
                }
                System.out.println("\n Your data has been copied successfully.");
            }
            catch (IOException e) {
                System.out.println("\n Error occurred in Files !!!");
            }
        }
    }

    private static void printSyntax() {
        System.err.println("\nError : No arguments or extra arguments !!!");
        System.err.println("Syntax : java FileName filepath1 filepath2");
        System.err.println("\nFileName  = .java filename");
        System.err.println("filepath1 = from where you want to copy");
        System.err.println("filepath2 = in which file data being copied");
    }
}

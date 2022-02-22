import java.util.Scanner;
public class Hello {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.printf("Input your name: ");
        String str = input.nextLine();
        System.out.printf("Hello %s.\n", str);
        input.close();
    }
}

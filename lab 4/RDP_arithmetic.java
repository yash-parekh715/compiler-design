import java.util.Scanner;

public class RecursiveDescentParser {
    private String input;
    private int position;

    public RecursiveDescentParser(String input) {
        this.input = input;
        this.position = 0;
    }

    public boolean parse() {
        boolean result = E();
        return result && position == input.length();
    }

    private boolean E() {
        return T() && E_dash();
    }

    private boolean E_dash() {
        if (position < input.length() && (input.charAt(position) == '+' || input.charAt(position) == '-')) {
            position++;
            return T() && E_dash();
        }
        return true;
    }

    private boolean T() {
        return F() && T_dash();
    }

    private boolean T_dash() {
        if (position < input.length() && (input.charAt(position) == '*' || input.charAt(position) == '/')) {
            position++;
            return F() && T_dash();
        }
        return true;
    }

    private boolean F() {
        if (position < input.length()) {
            if (input.charAt(position) == '(') {
                position++;
                if (E() && position < input.length() && input.charAt(position) == ')') {
                    position++;
                    return true;
                }
                return false;
            } else if (position + 1 < input.length() && input.substring(position, position + 2).equals("id")) {
                position += 2;
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        RecursiveDescentParser parser = new RecursiveDescentParser(s);
        System.out.println(parser.parse());
        sc.close();
    }
}
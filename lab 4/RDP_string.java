import java.util.Scanner;

public class seven{
    static boolean S(String[ ] s){
        if(s.length!=4){
            return false;
        }
        if(!s[0].equals("a")){
            return false;
        }
        if (A(s)){
            if (s[s.length - 1].equals("b")){
                return true;
            }
        }
        if (B(s)){
            if (s[s.length - 1].equals("b")){
                return true;
            }
        }
        return false;
    }
    static boolean A(String[] s){
    if(s[1].equals("c")&&s[2].equals("x")||s[1].equals("d")&&s[2].equals("x")){
        return true;
    }
    else{
        return false;
    }
}
    static boolean B(String[] s){
    if(s[1].equals("x")&&s[2].equals("e")){
        return true;
    }
    else{
        return false;
    }
}
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] s = sc.nextLine().split("");
        System.out.println(S(s));
        sc.close();
    }
}

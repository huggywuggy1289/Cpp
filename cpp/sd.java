import java.util.Scanner;

public class Main {

    
    static final double PI = 3.14;

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.print("반지름을 입력하세요");
        
        double r = sc.nextDouble();

        if(r<0){
            System.out.println("반지름 길이 오류");
            return;
        }

        double s = r * r * PI;

        System.out.println("원의 넓이 : " + s);
    }
}
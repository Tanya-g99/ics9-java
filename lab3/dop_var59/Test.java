import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Fraction[] Fractions = new Fraction[]{
            new Fraction(23, 45),
            new Fraction(8, 27),
            new Fraction(6, 11),
            new Fraction(4, 9)
        };
        System.out.println("До сортировки:");
        for (Fraction f : Fractions) System.out.println(f);
        Arrays.sort(Fractions);
        System.out.println("После: ");
        for (Fraction f : Fractions) System.out.println(f);//Некрасиво! Ужасно! ведет себя гоша!!! Из-за ужасающего кода Тани
    }
}

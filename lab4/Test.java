public class Test {
    public static void main(String[] args) {
        StringBuilder str = new StringBuilder("pqstlmabcc");
        SubstringList substrs = new SubstringList(str);

        System.out.println("строка до изменений: " + str);
        for (String s : substrs) System.out.println(s);

        substrs.setElem(1, 'r');

        System.out.println("строка после изменений: " + str);
        for (String s : substrs) System.out.println(s);
        
        substrs.setElem(100, 'r');

    }
}

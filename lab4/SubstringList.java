import java.util.Iterator;
public class SubstringList implements Iterable<String>{
    private StringBuilder str;

    public SubstringList(StringBuilder s){
        str = s;
    }

    public void setElem(int index, char elem){
        if (index >= str.length()){
            System.out.println("\u001B[31mИндекс элемента вышел за границы строки:\u001B[0m\nвведенный индекс: " + index + ", максимально разрешенный индекс: " + (str.length() - 1));
        }else{
            str.setCharAt(index, elem);
        }
    }

    public Iterator<String> iterator(){
        return new SubstringIterator();
    }

    private class SubstringIterator implements Iterator<String>{
        private int pos;
        
        public SubstringIterator(){
            pos = 0;
        }

        public boolean hasNext(){
            return pos < str.length();
        }

        public String next(){
            int pos1 = pos;
            int len = str.length();
            for (boolean flag = true; pos < len - 1 && flag; pos++) {
                if (str.charAt(pos) != str.charAt(pos + 1) - 1){
                    flag = !flag;
                    pos--;
                }
            }
            pos++;
            return str.substring(pos1, pos);
        }
    }

}

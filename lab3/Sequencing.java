public class Sequencing implements Comparable<Sequencing>{
    private int[] seq;
    public Sequencing(int... seq) {this.seq = seq;}
    public int difference(){
        if ((seq.length == 0) | (seq.length == 1)) return 0;
        int min = seq[0], max = seq[0];
        for(int i = 1; i < seq.length; i++){ 
            if (seq[i] > max) max = seq[i];
            if (seq[i] < min) min = seq[i];
        }
        return max - min;
    }
    
    public int compareTo(Sequencing obj) {
        if (difference() < obj.difference()) return -1;
        if (difference() == obj.difference()) return 0;
        return 1;
    }
    public String toString(){
        String str = "";
        for (int x : seq) str += x + " ";
        return str + "  разность: " + difference();
    }
}

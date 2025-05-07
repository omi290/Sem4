import java.util.*;
class WordExample {
    private String strdata;

    public WordExample(String sentence) {
        strdata = sentence.trim();
    }

    public void countWord() {
        String[] words = strdata.split("\\s+");
        int count = 0;

        for (String word : words) {
            word = word.trim().replaceAll("[.,!?]", "");
            if (word.length() > 0) {
                char firstChar = word.charAt(0);
                char lastChar = word.charAt(word.length() - 1);
                if (isVowel(firstChar) && isVowel(lastChar)) {
                    count++;
                }
            }
        }
        System.out.println("Number of words beginning and ending with a vowel: " + count);
    }

    private boolean isVowel(char ch) {
        ch = Character.toUpperCase(ch);
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    public void placeWord() {
        String[] words = strdata.split("\\s+");
        StringBuilder vowelWords = new StringBuilder();
        StringBuilder otherWords = new StringBuilder();

        for (String word : words) {
            word = word.trim().replaceAll("[.,!?]", "");
            if (word.length() > 0) {
                char firstChar = word.charAt(0);
                char lastChar = word.charAt(word.length() - 1);
                if (isVowel(firstChar) && isVowel(lastChar)) {
                    vowelWords.append(word).append(" ");
                } else {
                    otherWords.append(word).append(" ");
                }
            }
        }
        System.out.println("Rearranged sentence:");
        System.out.println(vowelWords.toString() + otherWords.toString().trim());
    }
    
    
}

public class program10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s;
        s=sc.nextLine();
        WordExample ob = new WordExample(s);
        ob.countWord();  
        ob.placeWord();  
        sc.close();
    }
}

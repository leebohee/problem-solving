package Day03.P2504;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Stack;

class Element{
	char ch;
	int val;
	public Element(int val) {
		super();
		this.val = val;
	}
	public Element(char ch) {
		super();
		this.ch = ch;
		this.val = -1;
	}
	@Override
	public String toString() {
		return "Element [ch=" + ch + ", val=" + val + "]";
	}
	
}

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day03\\P2504\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		
		Stack<Element> st = new Stack<>();
		for (int i = 0; i < str.length(); i++) {
			char ch = str.charAt(i);
			if(ch == '(' || ch == '[') {
				st.add(new Element(ch));
			}
			else {
				int acc = 0;
				boolean valid = true;
				while(!st.empty()) {
					if(st.peek().val > 0) {
						acc += st.pop().val;
					}
					else {
						if(acc == 0) acc = 1;
						if(ch == ')' && st.peek().ch == '(') {
							st.pop();
							st.add(new Element(2*acc));
						}
						else if(ch == ']' && st.peek().ch == '[') {
							st.pop();
							st.add(new Element(3*acc));
						}
						else {
							valid = false;
						}
						break;
					}
				}
				if(!valid) {
					break;
				}
			}
		}
		
		int result = 0;
		while(!st.empty() && st.peek().val > 0) {
			result += st.peek().val;
			st.pop();
		}
		if(!st.empty()) {
			result = 0;
		}
		System.out.println(result);
	}

}

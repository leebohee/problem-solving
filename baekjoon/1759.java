import java.io.FileInputStream;
import java.util.*;

public class Main {
	static int L, C;
	static char alpha[];
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		L = sc.nextInt();
		C = sc.nextInt();

		alpha = new char [C];
		for (int i = 0; i < C; i++) {
			alpha[i] = sc.next().charAt(0);
		}
		Arrays.sort(alpha);
		// dummy alphabet
		dfs(-1, "");
		//for (int i = 0; i < C; i++) dfs(i, Character.toString(alpha[i]));
	}
	
	static void dfs(int index, String pw) {
//		1. 체크인 => 정렬했기 때문에 이보다 앞에 있는 알파벳은 방문하지 않으므로 생략 가능
//		2. 목적지인가? => if(length == L) 자음&모음 개수 확인
		if(pw.length() == L) {
			if(isPossible(pw)) System.out.println(pw);
		}
		else {
//			3. 갈 수 있는 곳을 순회  => for(current+1 ~ C-1)
			for (int i = index+1; i < alpha.length; i++) {
//				4. 갈 수 있는가? => 생략 가능
//				5. 간다 - dfs(next)
				dfs(i, pw+alpha[i]);
				/* String + 하면 new로 새로운 객체를 생성하기 때문에 성능이 매우 안 좋음
				 * -> List<Character>를 쓰거나 StringBuilder를 쓰면 됨
				 * String + 연산이 말도 안 되게 느리기 때문에 StringBuilder가 성능에 좋음
				 * (+ 연산을 5~6번 이상 사용하게 되면 무조건 StringBuilder를 권장함)
				 */
			}
		}
//		6. 체크아웃 => 생략 가능
	}
	
	static boolean isPossible(String pw) {
		int vow = 0; // 모음
		int con = 0; // 자음
		for (int i = 0; i < pw.length(); i++) {
			if(pw.charAt(i) == 'a' || pw.charAt(i) == 'e' || pw.charAt(i) == 'i' || pw.charAt(i) == 'o' || pw.charAt(i) == 'u') {
				vow++;
			}
			else {
				con++;
			}
		}
		if(vow >= 1 && con >= 2) return true;
		else return false;
	}
}

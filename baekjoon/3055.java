import java.io.FileInputStream;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int R, C;
	static char[][] map; // 2-dim array
	static Queue<Point> queue;
	static int[][] dp; // 고슴도치가 몇 초만에 각 위치에 도달했는지 저장
	
	// 좌, 우, 위, 아래
	static int dr[] = {0, 0, -1, 1};
	static int dc[] = {-1, 1, 0, 0};
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		R = sc.nextInt();
		C = sc.nextInt();
		
		map = new char [R][C];
		dp = new int [R][C];
		queue = new LinkedList<>(); // 물 -> 고슴도치 순으로 큐를 초기화
		Point dochi = new Point(-1, -1, 'S');
		for (int i = 0; i < R; i++) {
			String line = sc.next();
			for (int j = 0; j < C; j++) {
				map[i][j] = line.charAt(j);
				if(map[i][j] == 'S') {
					dochi = new Point(i, j, 'S');
				}
				else if(map[i][j] == '*') {
					queue.add(new Point(i, j, '*'));
				}
			}
		}
		queue.add(dochi);
		
		while(!queue.isEmpty()) {
//			1. 큐에서 꺼내옴
			Point p = queue.poll();
//			2. 목적지인가? => if(p  == D)
			if(map[p.r][p.c] == 'D') {
				System.out.println(dp[p.r][p.c]);
				return;
			}
			else {
//				3. 갈 수 있는 곳을 순회 => for(좌, 우, 위, 아래)
				for (int i = 0; i < 4; i++) {
					int tr = p.r + dr[i];
					int tc = p.c + dc[i];
//					4. 갈 수 있는가? => if(맵을 벗어나지 않고, X가 아니고, *이 아니고)
					if(can_go(tr, tc)) {
						if(p.type == '*' && map[tr][tc] != 'D') { // water
//							5. 체크인 => spread water
							map[tr][tc] = '*';
//							6. 큐에 넣음 => queue.add(next)
							queue.add(new Point(tr, tc, map[tr][tc]));
						}
						else if(p.type == '.' || p.type == 'S'){ // dochi
							if(dp[tr][tc] > 0) continue;
//							5. 체크인 => dp[r][c] = time
							dp[tr][tc] = dp[p.r][p.c] + 1;
//							6. 큐에 넣음 => queue.add(next)
							queue.add(new Point(tr, tc, map[tr][tc]));
						}
					}
				}
				
			}
		}
		System.out.println("KAKTUS");
	}

	static boolean can_go(int r, int c) {
		if(r < 0 || r >= R || c < 0 || c >= C) return false;
		if(map[r][c] == 'X') return false;
		if(map[r][c] == '*') return false;
		return true;
	}

}

class Point{
	int r;
	int c;
	char type;

	public Point(int r, int c, char type) {
		super();
		this.r = r;
		this.c = c;
		this.type = type;
	}

	@Override
	public String toString() {
		return "[r=" + r + ", c=" + c + ", type=" + type + "]";
	}
	
	
}
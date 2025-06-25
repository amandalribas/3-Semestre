package Exemplo;

import java.util.HashMap;
import java.util.Map;

public class ExMap {
	public static void main(String[] args) {
		Map<String, Integer> map = new HashMap<>();
		map.put("Amanda",19);
		map.put("Diogo",21);
		System.out.println(map);
		//System.out.println(map.entrySet());

		map.remove("Amanda");
		map.put("Lais",18);

		System.out.println(map);
		System.out.println(map.size());
		System.out.println(map.values());
		
	}
}

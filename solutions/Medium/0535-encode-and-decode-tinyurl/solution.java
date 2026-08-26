// ──────────────────────────────────────────────────
// Problem  : 535. Encode and Decode TinyURL
// Difficulty: Medium
// Tags     : Hash Table, String, Design, Hash Function
// Link     : https://leetcode.com/problems/encode-and-decode-tinyurl/
// Runtime  : 3 ms (beats 70%)
// Memory   : 43668000 (beats 100%)
// Language : java
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

import java.util.HashMap;
import java.util.Map;

public class Codec {
    private Map<String, String> longToShort = new HashMap<>();
    private Map<String, String> shortToLong = new HashMap<>();
    private static final String BASE_HOST = "http://tinyurl.com/";
    private static final String ALPHABET = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public String encode(String longUrl) {
        if (longToShort.containsKey(longUrl)) {
            return longToShort.get(longUrl);
        }

        String code = generateCode();
        while (shortToLong.containsKey(code)) {
            code = generateCode();
        }

        String shortUrl = BASE_HOST + code;
        longToShort.put(longUrl, shortUrl);
        shortToLong.put(shortUrl, longUrl);

        return shortUrl;
    }

    public String decode(String shortUrl) {
        return shortToLong.get(shortUrl);
    }

    private String generateCode() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 6; i++) {
            int randomIndex = (int) (Math.random() * ALPHABET.length());
            sb.append(ALPHABET.charAt(randomIndex));
        }
        return sb.toString();
    }
}
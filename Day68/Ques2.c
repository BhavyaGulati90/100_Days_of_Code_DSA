//

using System;
using System.Collections.Generic;

class Solution {
    public string findOrder(string[] words) {
        
        int N = words.Length;
        int K = 26;

        List<int>[] adj = new List<int>[K];
        for (int i = 0; i < K; i++)
            adj[i] = new List<int>();

        int[] indegree = new int[K];
        bool[] present = new bool[K];

        for (int i = 0; i < N; i++) {
            foreach (char c in words[i]) {
                present[c - 'a'] = true;
            }
        }

        for (int i = 0; i < N - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = Math.Min(w1.Length, w2.Length);
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';

                    adj[u].Add(v);
                    indegree[v]++;
                    found = true;
                    break;
                }
            }

            if (!found && w1.Length > w2.Length)
                return "";
        }

        Queue<int> q = new Queue<int>();

        for (int i = 0; i < K; i++) {
            if (present[i] && indegree[i] == 0)
                q.Enqueue(i);
        }

        string result = "";

        while (q.Count > 0) {
            int u = q.Dequeue();
            result += (char)(u + 'a');

            foreach (int v in adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.Enqueue(v);
            }
        }

        int count = 0;
        for (int i = 0; i < K; i++) {
            if (present[i]) count++;
        }

        if (result.Length < count)
            return "";

        return result;
    }
}
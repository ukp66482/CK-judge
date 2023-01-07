int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
int num;
while( scanf("%d",&num) )
{
if( num == -1 ) break;
a[i][idx[i]] = num; // a[i][k] = j 表示第 i 個人的第 k 條邊連接到 j
idx[i]++; // idx[i] = m 表示 i 連接到的人有 m 個
}
}

for(int i=0;i<n;i++) ans[i] = 1.0 / (double)n; // ans[i] 是我用來紀錄答案的陣列

for(int i=0;i<100;i++) // 讓他收斂 100 次
{
for(int k=0;k<n;k++) // 去看第 k 個人會分流量給誰
{
int num = idx[k]; // num 表示第 k 個人會分給其他的人的人數
for(int j=0;j<idx[k];j++)
{
save[a[k][j]] += ans[k] / num; // 額外開一個 save 陣列存這一次收斂的結果
// 由於 k 有連接到 a[k][j]，因此他會被分到 ans[k] / num 的流量
}
}

for(int k=0;k<n;k++) ans[k] = save[k] , save[k] = 0.0; // 把這一次的結果更新到 ans 上，記得把 save 歸 0
}

for(int i=0;i<n;i++) ans[i] *= 100.0;
char u = '%';
for(int i=0;i<n;i++) printf("%.2lf",ans[i]) , printf("%c ",u);
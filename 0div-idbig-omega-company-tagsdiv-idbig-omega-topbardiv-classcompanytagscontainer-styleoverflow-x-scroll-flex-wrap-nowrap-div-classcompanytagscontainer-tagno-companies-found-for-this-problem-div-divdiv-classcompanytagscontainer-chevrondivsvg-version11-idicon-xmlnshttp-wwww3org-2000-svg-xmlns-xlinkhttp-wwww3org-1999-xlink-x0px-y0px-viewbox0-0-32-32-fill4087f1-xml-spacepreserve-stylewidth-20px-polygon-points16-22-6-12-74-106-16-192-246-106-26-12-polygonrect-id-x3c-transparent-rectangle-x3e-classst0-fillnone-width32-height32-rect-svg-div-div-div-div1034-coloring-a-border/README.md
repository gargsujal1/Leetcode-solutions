<h2><a href="https://leetcode.com/problems/coloring-a-border/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1034. Coloring A Border</a></h2><h3>Medium</h3><hr><div><p>You are given an <code>m x n</code> integer matrix <code>grid</code>, and three integers <code>row</code>, <code>col</code>, and <code>color</code>. Each value in the grid represents the color of the grid square at that location.</p>

<p>Two squares are called <strong>adjacent</strong> if they are next to each other in any of the 4 directions.</p>

<p>Two squares belong to the same <strong>connected component</strong> if they have the same color and they are adjacent.</p>

<p>The <strong>border of a connected component</strong> is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).</p>

<p>You should color the <strong>border</strong> of the <strong>connected component</strong> that contains the square <code>grid[row][col]</code> with <code>color</code>.</p>

<p>Return <em>the final grid</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
<strong>Output:</strong> [[3,3],[3,2]]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
<strong>Output:</strong> [[1,3,3],[2,3,3]]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
<strong>Output:</strong> [[2,2,2],[2,1,2],[2,2,2]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j], color &lt;= 1000</code></li>
	<li><code>0 &lt;= row &lt; m</code></li>
	<li><code>0 &lt;= col &lt; n</code></li>
</ul>
</div>
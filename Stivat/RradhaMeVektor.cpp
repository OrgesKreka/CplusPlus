<?xml version="1.0" encoding="iso-8859-1"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>RradhaMeVektor.cpp</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<meta name="generator" content="SynEdit HTML exporter" />
<style type="text/css">
<!--
body { color: #000000; background-color: #FFFFFF; }
.cpp1-assembler { color: #0000FF; }
.cpp1-character { color: #000000; }
.cpp1-comment { color: #316AC5; font-style: italic; }
.cpp1-float { color: #800080; }
.cpp1-hexadecimal { color: #800080; }
.cpp1-identifier { color: #000000; }
.cpp1-illegalchar { color: #000000; }
.cpp1-number { color: #800080; }
.cpp1-octal { color: #800080; }
.cpp1-preprocessor { color: #008000; }
.cpp1-reservedword { color: #000000; font-weight: bold; }
.cpp1-space { background-color: #FFFFFF; color: #000000; }
.cpp1-string { color: #FF0000; }
.cpp1-symbol { color: #000000; }
-->
</style>
</head>
<body>
<pre>
<code><span style="font: 8pt Courier New;"><span class="cpp1-comment">///     Implementimi i rradhes me lista te lidhura....
</span><span class="cpp1-preprocessor">#include &lt;iostream&gt;

</span><span class="cpp1-reservedword">using</span><span class="cpp1-space"> </span><span class="cpp1-reservedword">namespace</span><span class="cpp1-space"> std;

</span><span class="cpp1-comment">/// struktura e nyjes 
</span><span class="cpp1-reservedword">typedef</span><span class="cpp1-space"> </span><span class="cpp1-reservedword">struct</span><span class="cpp1-space"> nyje
{
        </span><span class="cpp1-reservedword">int</span><span class="cpp1-space"> vlera;
        
        nyje *pas;        
} rradhe;

</span><span class="cpp1-comment">/// shenjuesat e rradhes
</span><span class="cpp1-reservedword">typedef</span><span class="cpp1-space"> </span><span class="cpp1-reservedword">struct
</span><span class="cpp1-symbol">{
   rradhe *kreu;
   rradhe *fundi;        
} shRradhe;


</span><span class="cpp1-comment">/// krijimi i nje rradhe bosh...
</span><span class="cpp1-reservedword">void</span><span class="cpp1-space"> krijoRradheBosh( shRradhe &amp;r )
{
     r.kreu = </span><span class="cpp1-number">0</span><span class="cpp1-symbol">;
     r.fundi = </span><span class="cpp1-number">0</span><span class="cpp1-symbol">;     
}


</span><span class="cpp1-comment">//// kontrollimi nese eshte rradhe boshe apo jo
</span><span class="cpp1-reservedword">bool</span><span class="cpp1-space"> rradheBoshe( shRradhe r )
{
     </span><span class="cpp1-reservedword">return</span><span class="cpp1-space"> r.kreu == </span><span class="cpp1-number">0</span><span class="cpp1-space"> &amp;&amp; r.fundi == </span><span class="cpp1-number">0</span><span class="cpp1-symbol">;     
}

</span><span class="cpp1-comment">/// shton nje element ne rradhe. enqueue
</span><span class="cpp1-reservedword">void</span><span class="cpp1-space"> shtoNeRradhe( shRradhe &amp;r, </span><span class="cpp1-reservedword">int</span><span class="cpp1-space"> x )
{
     rradhe *eliri = </span><span class="cpp1-reservedword">new</span><span class="cpp1-space"> nyje;
     
     eliri-&gt;vlera = x;
     eliri-&gt;pas = </span><span class="cpp1-number">0</span><span class="cpp1-symbol">;
     
     </span><span class="cpp1-reservedword">if</span><span class="cpp1-symbol">( rradheBoshe( r ) ) </span><span class="cpp1-comment">/// shtimi ne fillim te rradhes
</span><span class="cpp1-space">     {
         r.kreu = eliri;
         r.fundi = eliri;    
     }
     </span><span class="cpp1-reservedword">else</span><span class="cpp1-space"> </span><span class="cpp1-comment">/// shtimi ne fund te rradhes
</span><span class="cpp1-space">     {
         r.fundi-&gt;pas = eliri;
         r.fundi = eliri;
     }
     
     cout &lt;&lt; </span><span class="cpp1-string">&quot;Elementi &quot;</span><span class="cpp1-space"> &lt;&lt; x &lt;&lt; </span><span class="cpp1-string">&quot; u shtua ne rradhe...\n\n&quot;</span><span class="cpp1-symbol">;
}


</span><span class="cpp1-comment">/// heq nje element nga rradha. dequee
</span><span class="cpp1-reservedword">void</span><span class="cpp1-space"> hiqNgaRradha( shRradhe &amp;r, </span><span class="cpp1-reservedword">int</span><span class="cpp1-space"> &amp;x )
{
     rradhe *tmp;
     
     </span><span class="cpp1-reservedword">if</span><span class="cpp1-symbol">( !rradheBoshe( r ))
     {
         x = r.kreu-&gt;vlera;
         
         tmp = r.kreu;
         
         </span><span class="cpp1-reservedword">if</span><span class="cpp1-symbol">( r.kreu == r.fundi ) </span><span class="cpp1-comment">/// rradha ka nje element
</span><span class="cpp1-space">             { r.kreu = </span><span class="cpp1-number">0</span><span class="cpp1-symbol">; r.fundi = </span><span class="cpp1-number">0</span><span class="cpp1-symbol">; } 
         </span><span class="cpp1-reservedword">else
</span><span class="cpp1-space">             r.kreu = r.kreu-&gt;pas;
         
         
         cout &lt;&lt; </span><span class="cpp1-string">&quot;Elementi &quot;</span><span class="cpp1-space"> &lt;&lt; tmp-&gt;vlera &lt;&lt; </span><span class="cpp1-string">&quot; u hoq nga rradha.\n\n&quot;</span><span class="cpp1-symbol">;
         </span><span class="cpp1-reservedword">delete</span><span class="cpp1-symbol">( tmp );    
     }     
     </span><span class="cpp1-reservedword">else
</span><span class="cpp1-space">         cout &lt;&lt; </span><span class="cpp1-string">&quot;Rradhe boshe...\n\n&quot;</span><span class="cpp1-symbol">;
}


</span><span class="cpp1-comment">/// afishon elementet e nje rradhe
</span><span class="cpp1-reservedword">void</span><span class="cpp1-space"> afisho( shRradhe r )
{
     </span><span class="cpp1-reservedword">if</span><span class="cpp1-symbol">( rradheBoshe( r ) )
                  cout &lt;&lt; </span><span class="cpp1-string">&quot;\nRradhe boshe....\n&quot;</span><span class="cpp1-symbol">;
     </span><span class="cpp1-reservedword">else
</span><span class="cpp1-space">     {
         </span><span class="cpp1-reservedword">while</span><span class="cpp1-symbol">( r.kreu != </span><span class="cpp1-number">0</span><span class="cpp1-space"> )
         {
                cout &lt;&lt; r.kreu-&gt;vlera &lt;&lt; </span><span class="cpp1-string">&quot; -- &quot;</span><span class="cpp1-symbol">;
                r.kreu = r.kreu-&gt;pas; 
         }  
         cout &lt;&lt; endl &lt;&lt; endl; 
     }
            
}

</span><span class="cpp1-reservedword">int</span><span class="cpp1-space"> main ()
{
    shRradhe r;
    
    krijoRradheBosh( r );
    
    
    </span><span class="cpp1-reservedword">int</span><span class="cpp1-space"> pergjigja;
    </span><span class="cpp1-reservedword">int</span><span class="cpp1-space"> element;
    </span><span class="cpp1-reservedword">bool</span><span class="cpp1-space"> perserit = </span><span class="cpp1-reservedword">true</span><span class="cpp1-symbol">;
    
    </span><span class="cpp1-reservedword">do
</span><span class="cpp1-space">    {
        cout &lt;&lt; </span><span class="cpp1-string">&quot;1. per te shtuar ne rradhe.\n&quot;</span><span class="cpp1-symbol">;
        cout &lt;&lt; </span><span class="cpp1-string">&quot;2.per te hequr nga rradha.\n&quot;</span><span class="cpp1-symbol">;
        cout &lt;&lt; </span><span class="cpp1-string">&quot;3.per te afishuar rradhen.\n&quot;</span><span class="cpp1-symbol">;
        cout &lt;&lt; </span><span class="cpp1-string">&quot;4. per te dale.\n&quot;</span><span class="cpp1-symbol">;
        
        cout &lt;&lt; </span><span class="cpp1-string">&quot;\nPergjigja&gt; &quot;</span><span class="cpp1-symbol">;
        cin &gt;&gt; pergjigja;
        
        </span><span class="cpp1-reservedword">switch</span><span class="cpp1-symbol">( pergjigja )
        {
                </span><span class="cpp1-reservedword">case</span><span class="cpp1-space"> </span><span class="cpp1-number">1</span><span class="cpp1-symbol">:
                       cout &lt;&lt; </span><span class="cpp1-string">&quot;\nElementi qe do shtoni&gt; &quot;</span><span class="cpp1-symbol">;
                       cin  &gt;&gt; element;
                       shtoNeRradhe( r, element );
                               </span><span class="cpp1-reservedword">break</span><span class="cpp1-symbol">;
               </span><span class="cpp1-reservedword">case</span><span class="cpp1-space"> </span><span class="cpp1-number">2</span><span class="cpp1-symbol">:
                      hiqNgaRradha( r, element );
                                    </span><span class="cpp1-reservedword">break</span><span class="cpp1-symbol">;
               </span><span class="cpp1-reservedword">case</span><span class="cpp1-space"> </span><span class="cpp1-number">3</span><span class="cpp1-symbol">:
                    shRradhe tmp = r;
                     
                     afisho( tmp );
                     </span><span class="cpp1-reservedword">break</span><span class="cpp1-symbol">;
              </span><span class="cpp1-reservedword">case</span><span class="cpp1-space"> </span><span class="cpp1-number">4</span><span class="cpp1-symbol">:
                     cout &lt;&lt; </span><span class="cpp1-string">&quot;~~~~~~~~~~~~~Mire u pafshim~~~~~~~~~~~&quot;</span><span class="cpp1-symbol">;
                     
                     perserit = </span><span class="cpp1-reservedword">false</span><span class="cpp1-symbol">;
                      </span><span class="cpp1-reservedword">break</span><span class="cpp1-symbol">;
              </span><span class="cpp1-reservedword">default</span><span class="cpp1-symbol">:
                      cout &lt;&lt; </span><span class="cpp1-string">&quot;Zgjedhje e gabuar....\nProvo perseri..\n\n&quot;</span><span class="cpp1-symbol">;
                       </span><span class="cpp1-reservedword">break</span><span class="cpp1-symbol">;       
        }   </span><span class="cpp1-comment">//// FUND switch
</span><span class="cpp1-space">    } </span><span class="cpp1-reservedword">while</span><span class="cpp1-symbol">( perserit ); </span><span class="cpp1-comment">/// fund do - while
</span><span class="cpp1-space">    
    
    cout &lt;&lt; endl &lt;&lt; endl &lt;&lt; endl;
    
    system( </span><span class="cpp1-string">&quot;pause&quot;</span><span class="cpp1-space"> );
    </span><span class="cpp1-reservedword">return</span><span class="cpp1-space"> </span><span class="cpp1-number">0</span><span class="cpp1-symbol">;
   
}

</span></span>
</code></pre>
</body>
</html>
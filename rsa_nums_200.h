#include<vector>
#include<string>

std::vector<std::vector<std::string>>rsa_nums {
    {"19", "43", "817"},
    {"47", "41", "1927"},
    {"61", "47", "2867"},
    {"97", "79", "7663"},
    {"97", "139", "13483"},
    {"97", "233", "22601"},
    {"251", "229", "57479"},
    {"457", "269", "122933"},
    {"443", "463", "205109"},
    {"829", "613", "508177"},
    {"997", "853", "850441"},
    {"887", "1901", "1686187"},
    {"1889", "1579", "2982731"},
    {"2699", "2411", "6507289"},
    {"3943", "3041", "11990663"},
    {"6473", "4159", "26921207"},
    {"7741", "5261", "40725401"},
    {"9029", "14737", "133060373"},
    {"9431", "25841", "243706471"},
    {"24851", "20341", "505494191"},
    {"28687", "28669", "822427603"},
    {"51829", "34367", "1781207243"},
    {"62761", "51343", "3222338023"},
    {"63391", "81307", "5154132037"},
    {"99679", "126341", "12593544539"},
    {"92077", "198533", "18280323041"},
    {"248063", "155627", "38605300501"},
    {"331367", "391019", "129570792973"},
    {"512929", "268721", "137834793809"},
    {"858127", "617983", "530307897841"},
    {"982343", "997783", "980165145569"},
    {"981703", "2082413", "2044311089339"},
    {"2063141", "1559777", "3218039879557"},
    {"3694499", "2328829", "8603856411671"},
    {"3972263", "3424481", "13602939170503"},
    {"5925461", "5458001", "32341172063461"},
    {"8031131", "7977287", "64066636921597"},
    {"9623893", "11398967", "109702438718531"},
    {"9526037", "26781331", "255119950015247"},
    {"9361399", "32890579", "307901833360021"},
    {"32830079", "28447451", "933932063678629"},
    {"57428897", "33571091", "1927950727216627"},
    {"63678499", "51175283", "3258765207340217"},
    {"83943469", "99346519", "8339491437934411"},
    {"96610369", "127256411", "12294288824325659"},
    {"191917237", "146837893", "28180722711461641"},
    {"261710143", "196354783", "51388038337663969"},
    {"441299801", "302526043", "133504682573217443"},
    {"522522529", "394809463", "206296839079891927"},
    {"827518271", "540768607", "447495902675718497"},
    {"972721481", "861619403", "838115701744495843"},
    {"934128421", "1518957893", "1418901738153576953"},
    {"2096081597", "1143523571", "2396918712908822887"},
    {"4158001669", "2152639873", "8950680184689948037"},
    {"4110491041", "4073785571", "16745259092550569411"},
    {"6378966221", "4865850593", "31039096569179819053"},
    {"7561509289", "8212262371", "62097098202021664219"},
    {"9788012219", "11204743223", "109672163577481441837"},
    {"16922482751", "9034397887", "152884442408428347137"},
    {"23527201309", "18870272737", "443964705439133412733"},
    {"34002938993", "17385740683", "591166279792167152219"},
    {"66135847567", "34533816701", "2283923237244054816467"},
    {"66224830169", "65484361273", "4336690704029865645137"},
    {"96249555893", "83166093611", "8004699575414414699623"},
    {"98409503201", "126780592541", "12476415127488216223741"},
    {"236436221149", "145290452491", "34351925556000353932159"},
    {"261625641311", "188961564383", "49437190464832191026113"},
    {"418735241377", "288556752391", "120828881363408606882407"},
    {"492286869031", "356559194521", "175529409494958379779151"},
    {"846402613583", "576629425199", "488060652557296599878017"},
    {"979913321927", "1162592397647", "1139239778425347508305769"},
    {"958055247971", "2173699017221", "2082523750957984154308591"},
    {"2176559305691", "1322553830933", "2878616847994502678739703"},
    {"4126762039669", "2326632712223", "9601459557054004987174187"},
    {"4351701104131", "2341742451523", "10190563211883073842541513"},
    {"7284283284917", "4911482548537", "35776630232469617252516429"},
    {"8470910520419", "6070687406779", "51424249820259368438520401"},
    {"8384244692051", "9502960948073", "79675149887648988886867723"},
    {"15385417382497", "12503184902363", "192366718333389755970140411"},
    {"19658293751989", "22099096500667", "434430530663664059871076663"},
    {"33788950753169", "35173082921111", "1188461566658549214060250759"},
    {"61580443075901", "36279155324987", "2234086459332132597562838287"},
    {"69396364989667", "36532718958149", "2535237898884635143390446383"},
    {"85384862587727", "76290013139083", "6514012288696489313739834341"},
    {"97438226743349", "175164006013301", "17067670135197370550007285049"},
    {"99533975897887", "225465371377709", "22441464840517029073492000883"},
    {"255882448288393", "157004882758793", "40174793793552055518720589649"},
    {"378759722011043", "356403500524051", "134991290782252174930109095193"},
    {"529241137479179", "501669149253593", "265503951189183581925428440147"},
    {"751507954354219", "802561442649899", "603131308009396447450650573881"},
    {"927484885162463", "1347441012909259", "1249731173121336908330491944917"},
    {"884034622402807", "1711254609967027", "1512808322957263482085782244789"},
    {"2123697338513039", "2288093665356227", "4859218427385563387604419343853"},
    {"3308628599018843", "2556846566523889", "8459655673304073821954520640427"},
    {"4318772127092011", "3394848031269769", "14661575053161066137133825715459"},
    {"7476469280366557", "4802073728107393", "35902556710250230044940901655901"},
    {"8862291121846601", "4642206213941669", "41140582915596376013550179917069"},
    {"9603239418304699", "11723933041809761", "112587735924672409566265490366939"},
    {"16595208437590331", "19061940148912723", "316336869996078311296291747681313"},
    {"21809274237531197", "19241485385798297", "419642831516323823753054286971509"},
    {"35259492593851637", "34771783448376061", "1226035440973028658048640816461857"},
    {"50524109865431479", "39593239155735383", "2000413165032677986797530842321457"},
    {"67526739392443291", "42677406060670567", "2881866077004381228583915980315997"},
    {"94597950035910757", "74467685120431013", "7044490356312467890935663843106841"},
    {"92436803421970171", "128687799834523693", "11895488856109712110461213438761503"},
    {"98115047628412363", "278890325277698513", "27363337547724805980422264755916219"},
    {"286406709152126137", "256394677733630129", "73433155893808915741112527511581673"},
    {"425892410346707159", "302020937993341013", "128628425257157389348597753535412067"},
    {"572586297536190611", "308591934362813029", "176695513146334264614132226698270719"},
    {"763802203705403227", "741486544242442919", "566349056510281868719648062425899613"},
    {"986456650436728423", "860875778438245769", "849216636840303074280646327581792287"},
    {"937105405441583269", "1633258650754191647", "1530535510105980012932117297934754043"},
    {"2138674313360971201", "1865449516734195911", "3989588964311061996025746438762959111"},
    {"2889052846900459489", "3617370351674315681", "10450774112797998041687882718537947009"},
    {"4202558821260765869", "3149219548029988319", "13234780391660269554654239041063884211"},
    {"8872787352484231213", "4744911624876835169", "42100591853862585956983893357485929997"},
    {"9201238365925228471", "6261967456981971743", "57617855211357756090712708185341094953"},
    {"9886227416712438889", "13916122935176189323", "137577956096079620838573422708531782147"},
    {"9560429266165507729", "26488076548135614527", "253237382235227968255885631926383179183"},
    {"26301356203139558897", "25186665367066614427", "662443457388497794511521657515956407019"},
    {"36321564177179988587", "23135574609170126717", "840320257942908589646075425259403778879"},
    {"65218034249751001067", "38047506880989432067", "2481383606882005665816977768181041015489"},
    {"69770382462263710151", "44982998197562083849", "3138480988543225699381554881201694451199"},
    {"92261860717252540121", "93183008236677703093", "8597237727146954461761080681458108294253"},
    {"98436841619537276329", "204086034972658504087", "20089584701362930757855758773299494856623"},
    {"84494418823579598629", "290037269756738003987", "24506530545273357439068530357924061733823"},
    {"257113280257328128063", "290409572879700282601", "74668157901229336837178687294207418731863"},
    {"419747200070628033689", "360981274185429647963", "151520879117261773123721624809270174225507"},
    {"523438149860633498009", "345735304365509784589", "180971048058585445467949859964347150383301"},
    {"950438572400477548789", "716426444009396460437", "680919326674241432624099623723102575760793"},
    {"987402652239706190077", "777013331944988601121", "767225024788092968296214106619908761276317"},
    {"943049349045634143569", "2118007342345514130143", "1997385445472810684642448751925063812500367"},
    {"1932963436406777353141", "1654113339017697249949", "3197340603993936786910010353055128917239809"},
    {"2901270549431271796561", "2917467673357924337381", "8464363039631119340711547836737209359546741"},
    {"4610862321630285939587", "2497773333045502435999", "11516888949312402772755440272777127047992413"},
    {"7283171304554702432761", "5234892740811928682717", "38126620592303156381430251023639553995291637"},
    {"8902516788025502941763", "7849423971810056050651", "69879628685368846140567673842145518231237713"},
    {"8795387824904354993861", "11546590854786727041763", "101556744623343148241529958970029860555616943"},
    {"9963018946353312127633", "28675025777386522065977", "285689825107271532075715464929590436670842441"},
    {"31465866607831872012281", "19326243719703377218999", "608117006914634926433367847001993311754526719"},
    {"37080569447677756749149", "30693988019643953874481", "1138150554388596689394969680112408145749566669"},
    {"55077877815736840666571", "46398270326093850518831", "2555518263882125437533868616985264468227698501"},
    {"72813921186780593788513", "46470923476053253311107", "3383730159462253659145708756447957874551913891"},
    {"92256074520910489521107", "80580162266293505915689", "7434009454946233159302427147153359749127947723"},
    {"99112066372994787990131", "187465850070462511160273", "18580127774853570059064563091846267134483265763"},
    {"235199435719870927775689", "164347620737114513556667", "38654467659272691336581608644288560226566468563"},
    {"278757736571652435498211", "203825819339267318064947", "56818024053876699525287045446574150496400309817"},
    {"454636793474554000836151", "304269782700998508915431", "138332238358381282705398587527859047002146546081"},
    {"595918772969517116794039", "336854227467885351629303", "200737757902256847574270025630575962372528124817"},
    {"773834421455275686852413", "835049436116018019249707", "646189997283392998335104145054881827566702492991"},
    {"912335046362972895019013", "840222038768419371624221", "766564012694977496628625316264794306002486313873"},
    {"916190521875674325593563", "1729861465100949835297367", "1584882678483457819018525926350805109090886048621"},
    {"2398208423795058248620951", "1917940198397785324148611", "4599620340132734044016846694983462948108932149061"},
    {"3044730133696025219774597", "2876817303935918652219467", "8759132334431848417672719899153201134991515479799"},
    {"4761915231688214064507781", "2694473725868499825033643", "12830855476596902734537924446281458095410560276183"},
    {"8468700739888354182913907", "5398797800433478997323321", "45720802927038622713694469156116317506485186325147"},
    {"8149088979323144329374769", "6113765556445673347694089", "49821619518196867760620134276062509642013247040441"},
    {"9622099664621925383001991", "17728888379191565336723849", "170589130927538711113552856042861210161144584183359"},
    {"19318595917436568835483733", "12507478169058374011251757", "241626916694198115087531132165515739880777941168881"},
    {"21789112060189546076959711", "20348719071428307541797847", "443380520128667557155520911088363340343344725542217"},
    {"37521612485393330321831393", "35063433245049784791676133", "1315636554628215580968707312518313072248234688243269"},
    {"45748837861597048670453173", "41481908085256569984877237", "1897749087182074502893311099953622907053881562123001"},
    {"77221182016212468518240309", "51827574543018556644945113", "4002186567245255712712057169890396594679242649159917"},
    {"88730698247941736393185201", "119780019087082965020567491", "10628164729748660187844754236304049528992174082900691"},
    {"85898398803146849973286601", "141316528266714027173971237", "12138863502530376184944882527084216760358313931495437"},
    {"254288988161940499265316913", "182584453401072037579646471", "46429215909459584093080866947120833658580822317064023"},
    {"309128893384130009577151703", "188245525624175597023413259", "58192131020715291906332364234499479183494024304630077"},
    {"394506952594067183260644929", "447418363177640124855695503", "176509654991836406961748797793160389703541938625054287"},
    {"581273763468983818098901241", "473132702925509282431176409", "275019626849763470775658224122287700113812405940023569"},
    {"897031491652398541031798603", "765523965150479639079517847", "686699104354593507997692116496009840668934100448167741"},
    {"932951147976952357187305529", "1442055823728473232233900161", "1345367636194328754758628008641744235717539998389290169"},
    {"797832638023788889108931881", "2263787396608852030677404737", "1806123470561445657131136324986310855048926595199720297"},
    {"2425535911586619729214793407", "2294766779496013072330875097", "5566039232383553655063032741738670105457474806376085479"},
    {"3268543852782089593773036167", "2845073277140612565513349661", "9299246770712543544096028684515763502114654182270189387"},
    {"4548550083964931818422767929", "4764545701019674436361190441", "21671774748427795089386967024681426349593014516716166689"},
    {"6000890776128607892169951287", "7811224271930344484493994403", "46874303683698705020382210033403126054322734368560646661"},
    {"9776748373571023645194887959", "9721275397807170355266133807", "95042463434547258652181240624143111188633988234467129913"},
    {"9640130242768181058447816107", "14562291753887179017956550529", "140382389140661492199997761389487220626431065235045570603"},
    {"19560297619855945501847925413", "14652150224762185346168660383", "286600419167187530945184800334665239355458396205912013179"},
    {"22393188941291935461422982263", "30576367668308019372438798191", "684702378334831421596396513766182816390377553738829486233"},
    {"39151800084787470667424532053", "25152171126767826850730030341", "984752775653577574927281362376225303860846451776417020073"},
    {"51791209509298141653435683933", "53605683176591489318780390707", "2776303168287908554831109315875875976093104550057502410631"},
    {"78799948622966341369442732173", "58965026101771708418952833239", "4646441027371479910659060630450612660694849346435409098347"},
    {"96349180417414362363600272443", "129360725541111003778709444633", "12463799884088126269691105912286652525701975697496024148419"},
    {"82844567306127579525849085841", "277245378848539266073038946181", "22968273448330650841949064101023588656801421585068848123221"},
    {"90727630029660461418918406207", "301035493034345955175274021309", "27312236837816568740009145371605688796031619790258035864963"},
    {"315122927564372777124796603963", "312224731074972048928138993621", "98389171314344187065247128895054991990248676150537320320023"},
    {"587772076079315470053935600269", "339678862766238627189646444393", "199653750368372969282339036536582110923627745190217984341717"},
    {"611585883180231501101911568279", "441543210784267239035591079367", "270041594529731197574560271452069888587482994263033328599393"},
    {"807675367303992524529448365407", "968894446146109221960813160201", "782552177669857170155801624711294408688959412400953477566807"},
    {"947511575218509653727922878601", "1063958408654550462646564121119", "1008112907751251923235242324743404124340265941614068097274519"}
};
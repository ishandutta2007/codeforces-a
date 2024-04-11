#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
vector< vector<unsigned int> > cur = {{2152465, 2215791, 2237451, 2251059, 2261029, 2268806, 2275202, 2280659, 2285358, 2289514, 2293223, 2296568, 2299622, 2302454, 2305031, 2307454, 2309707, 2311814, 2313779, 2315692, 2317451, 2319145, 2320741, 2322286, 2323744, 2325145, 2326509, 2327772, 2329038, 2330201, 2331397, 2332524, 2333582, 2334634, 2335636, 2336632, 2337575, 2338514, 2339398, 2340315, 2341104, 2341996, 2342785, 2343571, 2344318, 2345094, 2345862, 2346516, 2347278, 2347950, 2348602, 2349296, 2349925, 2350562, 2351160, 2351777, 2352414, 2353000, 2353519, 2354100, 2354698, 2355210, 2355774, 2356250, 2356816, 2357318, 2357814, 2358311, 2358801, 2359316, 2359740, 2360195, 2360690, 2361130, 2361596, 2361972, 2362452, 2362852, 2363293, 2363744, 2364152, 2364512, 2364893, 2365345, 2365726, 2366092, 2366456, 2366873, 2367189, 2367562, 2368036, 2368282, 2368679, 2369011, 2369328, 2369696, 2370089, 2370348, 2370748, 2371027, 2371345, 2371696, 2371993, 2372333, 2372620, 2372937, 2373233, 2373564, 2373843, 2374112, 2374401, 2374755, 2374982, 2375308, 2375582, 2375854, 2376134, 2376417, 2376710, 2376923, 2377208, 2377471, 2377740, 2378008, 2378303, 2378520, 2378758, 2379029, 2379300, 2379505, 2379789, 2380028, 2380234, 2380536, 2380703, 2380942, 2381243, 2381421, 2381716, 2381868, 2382152, 2382399, 2382557, 2382784, 2383040, 2383247, 2383450, 2383686, 2383873, 2384166, 2384267, 2384502, 2384742, 2384964, 2385146, 2385372, 2385535, 2385752, 2385979, 2386093, 2386443, 2386530, 2386722, 2386951, 2387105, 2387342, 2387497, 2387741, 2387871, 2388092, 2388247, 2388477, 2388616, 2388771, 2389028, 2389183, 2389337, 2389524, 2389696, 2389865, 2390065, 2390251, 2390373, 2390608, 2390735, 2390942, 2391026, 2391267, 2391424, 2391628, 2391729, 2391899, 2392119, 2392185, 2392438, 2392543, 2392694, 2392927, 2393105, 2393142, 2393353, 2393479, 2393706, 2393810, 2393945, 2394134, 2394279, 2394408, 2394543, 2394778, 2394848, 2395031, 2395137, 2395323, 2395417, 2395638, 2395771, 2395869, 2396044, 2396169, 2396318, 2396447, 2396614, 2396749, 2396852, 2397011, 2397135, 2397279, 2397482, 2397551, 2397738, 2397808, 2397945, 2398066, 2398247, 2398396, 2398466, 2398643, 2398712, 2398889, 2398947, 2399197, 2399275, 2399410, 2399527, 2399615, 2399798, 2399884, 2400028, 2400175, 2400258, 2400427, 2400478, 2400709, 2400730, 2400868, 2400981, 2401148, 2401274, 2401344, 2401464, 2401612, 2401715, 2401808, 2401975, 2402069, 2402192, 2402281, 2402425, 2402509, 2402646, 2402746, 2402879, 2402953, 2403129, 2403196, 2403337, 2403428, 2403482, 2403631, 2403811, 2403878, 2403954, 2404081, 2404204, 2404295, 2404422, 2404463, 2404634, 2404762, 2404823, 2404966, 2405017, 2405147, 2405213, 2405383, 2405457, 2405582, 2405635, 2405752, 2405895, 2405985, 2406069, 2406163, 2406319, 2406374, 2406466, 2406542, 2406672, 2406754, 2406930, 2406948, 2407048, 2407177, 2407282, 2407385, 2407393, 2407586, 2407673, 2407704, 2407890, 2407919, 2408029, 2408108, 2408195, 2408340, 2408424, 2408512, 2408581, 2408700, 2408743, 2408916, 2408950, 2409039, 2409129, 2409294, 2409270, 2409440, 2409490, 2409552, 2409715, 2409777, 2409831, 2409970, 2410031, 2410111, 2410256, 2410278, 2410402, 2410469, 2410576, 2410679, 2410664, 2410854, 2410935, 2411002, 2411126, 2411072, 2411285, 2411300, 2411419, 2411491, 2411602, 2411696, 2411710, 2411853, 2411900, 2412070, 2412057, 2412179, 2412307, 2412264, 2412375, 2412423, 2412688, 2412649, 2412711, 2412777, 2412881, 2413071, 2413000, 2413144, 2413236, 2413314, 2413320, 2413470, 2413507, 2413575, 2413759, 2413774, 2413821, 2413921, 2413999, 2413977, 2414193, 2414224, 2414276, 2414448, 2414435, 2414511, 2414575, 2414677, 2414777, 2414811, 2414943, 2414967, 2415050, 2415100, 2415211, 2415237, 2415400, 2415425, 2415465, 2415521, 2415637, 2415719, 2415795, 2415847, 2415904, 2416021, 2416086, 2416146, 2416206, 2416241, 2416352, 2416441, 2416497, 2416622, 2416610, 2416632, 2416879, 2416813, 2416936, 2416981, 2417031, 2417142, 2417150, 2417272, 2417374, 2417413, 2417453, 2417543, 2417561, 2417688, 2417765, 2417772, 2417911, 2417953, 2417994, 2418082, 2418110, 2418279, 2418220, 2418376, 2418390, 2418455, 2418542, 2418626, 2418621, 2418716, 2418877, 2418870, 2418899, 2418980, 2419084, 2419138, 2419123, 2419264, 2419310, 2419359, 2419500, 2419541, 2419558, 2419578, 2419702, 2419794, 2419799, 2419905, 2419957, 2419970, 2420096, 2420124, 2420194, 2420250, 2420352, 2420435, 2420337, 2420525, 2420562, 2420631, 2420628, 2420798, 2420852, 2420854, 2420934, 2420987, 2421069, 2421105, 2421190, 2421171, 2421341, 2421347, 2421368, 2421565, 2421494, 2421552, 2421695, 2421681, 2421774, 2421813, 2421867, },{2914984389, 3505082543, 1517509766, 2911557212, 3282949189, 3095190405, 2956717922, 1627685412, 924944973, 3060871019, 1633731012, 4093255126, 1668291650, 3717751226, 1760500059, 2531506683, 3590196398, 1987612934, 2528105296, 4235816584, 675138537, 605305076, 2768053030, 3462623851, 2732405143, 3834053798, 56262421, 1339390864, 1426336153, 3290997034, 4048862967, 1409855507, 1402105426, 923980217, 2013850782, 1623422438, 1507261422, 3789329100, 1969397005, 4096629524, 1235870326, 3152841340, 2649479835, 2335043600, 3787880787, 2530150078, 3356226882, 2715371825, 2025141381, 3472482278, 578193326, 3240451461, 118083338, 135979717, 508926639, 3081289706, 1442099607, 84186938, 834628033, 2251620523, 806757762, 3319325132, 1232745029, 296755202, 1009390649, 2078611437, 1277159913, 1302384215, 995231184, 1555937199, 2796082464, 1960105033, 659776862, 3401593301, 2490424097, 75958801, 4284714824, 3597967875, 524546899, 3677224647, 2907579288, 3012268046, 627053519, 3371905899, 3604610239, 2410593193, 1403060014, 798467712, 2936914452, 798065836, 1215694743, 1490083787, 1399444306, 592030272, 1491772047, 3118638018, 3355875036, 3502215672, 3649662210, 153978665, 3720351018, 1620525299, 1659775970, 602974737, 54628012, 2091131698, 3539797404, 631113420, 2728886820, 3097339562, 965302653, 342173376, 1171741754, 3489359465, 319807331, 1985614735, 3610195631, 2207349930, 1389850397, 1581308683, 3459384874, 3199153521, 1425475828, 693616870, 2659251290, 3921844440, 3875812231, 3631388484, 188344747, 579246835, 2865407199, 2656191193, 1548485920, 1380874997, 3925337503, 1935184134, 3241560805, 703480514, 513830093, 506980130, 1863601603, 2213647116, 2034784584, 3933579307, 689873019, 2891379048, 3701551051, 1169785664, 1759454258, 225269850, 606878975, 3000517699, 138394005, 2888503905, 910634091, 4243823998, 4127821653, 1618201632, 3474288066, 4181237709, 3323529870, 4156617239, 1566844976, 623431435, 1571189625, 2027464248, 513779369, 141546075, 3155193951, 3021526197, 1421280981, 399563320, 2791411836, 3933998245, 112616634, 1954870692, 2199586603, 2616861149, 429852914, 3678456637, 1767879879, 1392067084, 2281244745, 3617906473, 3460998815, 4080805877, 1603991477, 3921474549, 850806656, 1634825899, 712710818, 1958307340, 2625412110, 1015825677, 1944999555, 2022013998, 2753484332, 2021535815, 2825693962, 3531355999, 1963074638, 2303587215, 607401796, 3980670391, 1971479403, 2807463529, 3086005189, 1075471938, 3157982571, 4118114018, 576596435, 3943119613, 470480399, 3669598664, 273193894, 403772293, 4015392942, 2127155215, 4205564506, 2460731309, 3528031665, 2443099112, 2222174156, 1061847820, 4142737504, 2682163543, 2839704284, 2707847479, 782500451, 3437817287, 1425734171, 3707106748, 2837784100, 2427249972, 445989211, 741650601, 1497841708, 2172502228, 2131578015, 1711804550, 4043221439, 2567303411, 2932700725, 1636512090, 712356039, 648367787, 83208634, 159409506, 3823792158, 2701619248, 2666466066, 3457543607, 2395576518, 2886429402, 404373831, 3806569234, 3458599763, 1848453449, 3613082370, 1570510278, 290194596, 2995595526, 831257109, 710088115, 3985177017, 185240769, 1515728169, 1700990157, 3113164006, 1856718348, 2057528868, 2874939244, 3388309658, 948823048, 1016148311, 3596546811, 406597384, 3766531510, 1750738513, 77473086, 3398074141, 619953979, 2708858618, 1533341958, 119410947, 3535235515, 982570474, 4224819402, 2591076182, 2779083857, 3320807900, 1877955954, 2917445439, 376476618, 2700788884, 3860494114, 557146513, 1714879419, 666397698, 1543201921, 107898743, 3449891577, 3157583498, 335091751, 4034956280, 417190600, 1793511111, 2744790558, 2548204543, 1106901812, 126184087, 732432677, 2981715297, 329248122, 1869609023, 3614970044, 247668842, 3655616524, 458406198, 2241416127, 3333152164, 1177099728, 841030164, 3281536678, 1463838531, 2288001754, 3544044426, 421232070, 1535522620, 241728333, 1826086188, 3345292305, 3006977399, 1020637310, 538354823, 1632535110, 3575518981, 1831279041, 814214806, 3465667181, 705442562, 2011299128, 1615942975, 2055294509, 2160186550, 3029343088, 735402806, 2513323618, 2969182374, 2085259931, 2323285438, 2154060062, 2106004075, 1367258961, 1402367268, 2742771666, 3579251890, 1830983958, 3057755759, 2223418782, 1096491713, 2697345915, 2893934473, 1463226250, 2921760271, 730475784, 3067977548, 1596120259, 3959797953, 2961343743, 3460418550, 435847032, 1073901374, 3281619675, 2693363104, 3535675759, 3039599971, 644194493, 712403328, 1923015307, 3180702770, 1187426543, 3860666002, 2035531385, 3982660642, 3919409827, 3327525037, 3740054729, 1789734737, 203700125, 2629333874, 1541299099, 2471976647, 3390561635, 305532022, 826535235, 3328077999, 1850337902, 3238991655, 3007330308, 636146476, 3962634973, 1648493240, 1727021624, 747433951, 2646233913, 328860510, 221033921, 777490462, 1588327520, 1563503036, 2280696520, 1766655040, 445838680, 919094831, 2762146679, 735318809, 2704877305, 385645647, 3473100318, 1784311867, 1197042820, 1432430021, 3802558684, 2381487426, 1229572257, 424862039, 1230529269, 3514496944, 957210667, 3181901065, 2320869862, 2653713537, 3302248623, 243204136, 3716014567, 918375609, 44571647, 394599765, 650733602, 3368525886, 544939181, 1962539145, 1074528701, 1652309028, 751976727, 3085481977, 4021613026, 1373681393, 2861158847, 3807508958, 3676710875, 3092561696, 1449548681, 2177911363, 1532644154, 4229577412, 2367973909, 4239474079, 529519574, 3465638977, 2612356087, 1523587915, 3645930952, 1421660592, 3306366109, 722134424, 2655355025, 2137350406, 1427369795, 3215861581, 65355561, 1608318606, 2658712704, 2856503671, 2298705350, 1785346413, 658390414, 3241281388, 4096810656, 4084279995, 3331676953, 344808893, 1689663717, 2953663046, 3818051219, 3428195658, 4055119480, 4190271348, 2736609717, 279786296, 3904813122, 2178587783, 1002107563, 2470277586, 2634485317, 625571164, 3052489484, 3542725202, 2300490568, 2028326396, 1986372676, 2067519187, 494263170, 3066856974, 3447668944, 1701549035, 968516670, 4207148297, 4084671399, 3325255430, },{3084627665, 2121787311, 1627094514, 2787095692, 1365201687, 1868680955, 3972245900, 4268671394, 2850463283, 3376157783, 687575986, 3912849314, 388090820, 75111010, 1162253873, 2442891299, 31146458, 3055897340, 2406857794, 4016796298, 1475712015, 2512515248, 1703913392, 774809037, 3880363347, 2337962948, 3821932455, 2083068110, 51891563, 1480428070, 3518326087, 2917331407, 3975263106, 1903847365, 980489962, 4185910488, 3689455310, 321240122, 3990303079, 4162818520, 361748188, 2626941764, 2497710013, 3050083038, 3034907919, 4148520384, 1883252952, 4228469665, 229720297, 370409414, 4113322580, 3692093377, 4059852140, 2150002261, 2978422461, 3614060622, 503826807, 1787847404, 3749460865, 1666962927, 3582135670, 3181745824, 2926296511, 606210364, 2487977407, 2907364491, 4056393673, 4185118511, 1486948272, 1856956235, 3971984554, 1224938293, 4027464932, 3628167839, 4189207191, 2828923073, 838004210, 1734631463, 4138434237, 1445062717, 4139504314, 270537290, 870150893, 1543452905, 2913825717, 1284774833, 1204279718, 170394166, 3842006220, 151633700, 326229209, 3296845279, 3310529814, 4111991958, 1539074267, 3399596738, 2250537878, 1595222106, 490795678, 447760265, 308160312, 2667652259, 1631816240, 2049934311, 2618528870, 2731358902, 628323678, 1653856770, 2997314242, 2920738166, 657966385, 1569351520, 2991187450, 1445863729, 2149142347, 403610693, 2974911151, 2789827274, 313102531, 2403889689, 1319406772, 1488809263, 1827968778, 2623669040, 691367404, 1331026028, 2752875957, 1799494536, 3369488707, 611549249, 1337037223, 3397664871, 2197415080, 796847917, 2040673385, 3075232332, 871684619, 1297543676, 195610477, 3318157002, 2119462389, 72285760, 3524391164, 2975296723, 1684190191, 402439250, 1070938333, 1213998456, 3658432682, 1675487064, 1209410275, 81613931, 1986972369, 2059720631, 490159453, 2518318588, 4194706977, 742246678, 739641914, 3642766731, 1855449436, 1595106835, 3324513090, 4119365713, 3766854913, 3551762750, 4067821457, 1806963837, 2740497005, 4253404869, 222207441, 1415593512, 2635831956, 2293770437, 4101509748, 320119948, 4017468245, 2910843343, 3233171120, 1103968723, 2658179375, 2557625314, 3901726609, 4034154217, 1223601725, 3833852127, 1966857643, 1960968269, 1467540872, 3860242095, 3384517574, 921466152, 313759784, 484019381, 2930549899, 1123866168, 3070749128, 2500889583, 3846034870, 1464289415, 2920656934, 1371641361, 3388236942, 508243617, 80257953, 1163489573, 986842155, 325208798, 1704438613, 3929899982, 3132730285, 143180343, 4022673641, 3237765184, 234893450, 2797619531, 2224669656, 1048433519, 3748421448, 512477539, 3402328515, 2596891242, 815556470, 3879157594, 591857836, 2415599183, 164666830, 3469323013, 1775286397, 1723234057, 2965534389, 1528965948, 613026386, 1783011330, 258986969, 2834142003, 4051626310, 1184265324, 3798846011, 655831908, 1159537097, 3657557491, 451936067, 2624365258, 2642532413, 4000610727, 2738227816, 242781618, 2823959264, 3474431256, 3831391742, 4207492995, 3620800776, 3307342026, 3964616567, 1016043002, 173381313, 3796312175, 3810884610, 3577486856, 2421182200, 2329738022, 3036448443, 202996595, 950777919, 3298121963, 292421525, 4198878233, 448029318, 1704490378, 2306482946, 2781691660, 3312389052, 1341751388, 2537494427, 675974249, 369091704, 3119062158, 2491962943, 1142145000, 2014375891, 3617311267, 2036842836, 1042510352, 1006302353, 1758072449, 866051356, 524128940, 545074344, 2631745467, 2792084554, 4017352502, 3257481301, 4111102242, 3784687394, 1199012596, 3853129163, 1930572157, 1426120210, 1322995675, 1962898625, 3688590591, 3157016408, 3844524709, 928486844, 851326212, 1036707729, 2005646770, 1503872783, 531063238, 2037957145, 2562585277, 1293776367, 3704567364, 3792178239, 4010194314, 1393777744, 4238993970, 613191130, 2773459989, 2529674040, 3767122202, 3236891822, 199639820, 1955487223, 1841395328, 1471240784, 3261602018, 2058682462, 3439387587, 2534889554, 2948461017, 2663351153, 775441276, 2031564039, 38728784, 79471583, 3682260549, 652307370, 4141371841, 1760555026, 2003220620, 3414107651, 288548481, 2876729412, 2248244342, 4010488924, 3622429692, 3706978390, 1895468161, 3378752032, 1220529140, 2243200531, 1136728247, 2085884658, 671843258, 616440182, 2184331184, 3495334943, 3389493124, 546598713, 2057899331, 841664297, 135638224, 3473870871, 244935136, 129029944, 3584696515, 115865181, 831486269, 1587823524, 2503184024, 3812079326, 2457949881, 2155861956, 1772294687, 931027883, 3696795693, 1785081736, 2407119675, 1379205736, 4218005005, 2104474886, 3944701245, 1138218858, 386905581, 2231388705, 3330237413, 1457950385, 1071440753, 268327452, 303111195, 2629657471, 2847362651, 1804571538, 3324447615, 612595071, 3112977626, 1298675217, 1848519378, 3175717374, 280486051, 2714254438, 1793169080, 4058122153, 983757457, 4169605812, 895089889, 3298272068, 3968251444, 4254556952, 421254432, 3142851976, 2114635718, 832164671, 3865877107, 919309307, 4085809797, 2541226787, 918348550, 104799621, 3349275888, 3928550017, 1713829022, 2915300524, 78792405, 3569520497, 3397159219, 2668023220, 161494167, 2208723075, 3649131566, 1109819113, 1191562993, 3126881508, 1220281643, 2704374713, 3020700601, 2860298773, 2499805736, 509617276, 3578692573, 2165503611, 159793217, 1285727546, 708674887, 46951969, 4112364484, 2066102669, 3936986583, 749068472, 1405650089, 2596673854, 2398344885, 2071141343, 1845519860, 3020017610, 94603065, 543049597, 905773494, 2849575373, 1377519025, 3324840107, 2988210008, 3857951032, 3366271599, 2415960790, 2866318765, 3902237326, 661139569, 4150240643, 399222837, 108921370, 143804874, 4288423937, 446621440, 2250944151, 3160725956, 3683273904, 1170859842, 1828950051, 3876704927, 3011226183, 1700091275, 972784064, 481869675, 3978208734, 3797208472, 1828936982, 1383498729, 254350520, 2881028930, 1822162569, 1138206163, 2167417880, 3335263567, 1947490468, 2193945566, 3657175030, 3443637868, 1461852716, 3483490576, 3094354171, 3198370514, 2365227852, 1145059716, 4253677649, 1496625508, 1131073969, 3359522351, 1749030502, },{2874015853, 586063183, 1965009476, 2705159310, 2893244449, 1190427575, 1296253326, 1086663210, 2510724223, 794261765, 9619858, 322647098, 2413492710, 2023723330, 3126258079, 2077576829, 1647169812, 1549617618, 2017117542, 1731336908, 3449066105, 470996306, 2402738644, 123511185, 2648231725, 2004133412, 3505697993, 4270503140, 2928847939, 334179908, 954005283, 4183012297, 3165925706, 724661831, 2968460890, 954389446, 2640591484, 1904333332, 4262442263, 1830748030, 3160085174, 926928124, 894715131, 2212978414, 909894357, 1013641882, 3411896782, 2486074123, 2931042195, 200084542, 67415090, 3274284751, 3070021064, 1369148139, 3060634353, 1964420172, 3238823057, 259847898, 2775879389, 199077657, 1004715394, 2002760264, 4262431199, 1930608574, 104940415, 82841679, 3099423599, 618197839, 2334285142, 2963974149, 2892849892, 2038050085, 727849994, 4224853079, 486468639, 2815779771, 1633184236, 3394785161, 3562342835, 491968625, 2435999940, 343607874, 2217507791, 377568491, 3155132973, 3483516171, 800525826, 1075310970, 239951682, 1893341104, 1802937921, 1159315901, 2767589592, 556109702, 4285060861, 3992754878, 2306436070, 677391580, 2742218878, 3546088341, 869616984, 4032726345, 892601264, 576759677, 3321943888, 1606254172, 1442137382, 2248752856, 34309386, 3035384758, 1193261389, 1767349778, 4215322882, 2913894523, 1378326013, 2646177173, 2457156937, 2892377196, 532592359, 1373326927, 4137655354, 85712033, 733448648, 501718494, 2678397956, 2023515160, 2656670125, 2085497226, 3320310689, 54936691, 1463757363, 4106160311, 2415315284, 542278663, 2406206643, 3301020890, 3284765701, 500178424, 3576958079, 3086039334, 2768514733, 1212362630, 2641705022, 985559761, 3685231137, 1431620558, 980457137, 1627354524, 3102429508, 908134166, 289629815, 1146499829, 244695491, 3104052439, 2443790993, 890924894, 2113856049, 792753828, 758212312, 2957772225, 2087823296, 3511265233, 3886236848, 1069208175, 1477367209, 3804858152, 2608634113, 3804079203, 2113523099, 4078267927, 952442281, 3017554758, 4141863180, 670306809, 3518806922, 2996089246, 2577696587, 1549294843, 1674052434, 1133224625, 2447096955, 1676071554, 3747875257, 2632014315, 755445851, 1081235663, 1738123335, 2358463689, 4093817416, 4177973697, 3922069556, 313893430, 2677378768, 2415493205, 2665020453, 2662112688, 3251478584, 542006951, 533961468, 2849371209, 1081804056, 4188979459, 2504685940, 1306557741, 1890026835, 1433200895, 1389832645, 1789529934, 3967065727, 218313458, 3391610461, 925057965, 3956186055, 148330394, 3396977200, 1180106087, 620939800, 3865829931, 3445762658, 3391758193, 830883027, 3892017878, 2318385116, 682970958, 1562857488, 1581271135, 2682194466, 1635740611, 3549592825, 2329712635, 3434278521, 231115972, 1185494734, 1992833924, 1722886871, 4086009423, 2603518916, 600025958, 4079186677, 1723254948, 460753843, 1195961215, 4024834173, 1470565426, 2356463027, 4275943459, 397239958, 1433454782, 1323408326, 1624674082, 1700681010, 1203937495, 3297180298, 2705434332, 1269280689, 3663852222, 3122853011, 4071493007, 1327191594, 3212869406, 1846389668, 3608292026, 3704245693, 1413584393, 2851235073, 4104832237, 1569266011, 193739405, 2041091696, 573328854, 2727342892, 3488746344, 2677962484, 2858296462, 551162451, 1124974005, 474201558, 3928485866, 2170322451, 2234331632, 4195359805, 1952372789, 4144939318, 4213114772, 3727874821, 594065295, 3587197558, 2091801396, 3086842226, 2624487707, 2496112450, 2036732370, 950983167, 3447565344, 2246409398, 2910468844, 1718256901, 256088825, 2823138104, 1459121271, 14288955, 635298685, 3294059488, 4149991571, 2191528050, 2365065788, 965650189, 2880926446, 3688421733, 2100698644, 456974565, 1654755207, 118935871, 3069868552, 1517724697, 2324784470, 4106927168, 249398412, 2237497504, 2683329593, 1840963272, 4028710222, 3363332254, 1966450054, 3026528779, 1815217218, 4212658018, 1767432162, 167420414, 1992459611, 62682730, 4048632067, 1007490661, 3740935544, 2231827163, 1693144602, 3986947967, 415244243, 608708158, 2718136231, 4192380744, 281974454, 3441142567, 3900117699, 3641349256, 819588830, 2559964046, 1854611582, 3917690638, 45976291, 3268696302, 2797102856, 110954657, 2747298507, 2113703058, 1407026866, 2999534898, 1442558550, 3456532227, 833875566, 4005506677, 2034565803, 244744199, 3724800722, 2972992121, 2734788158, 3483969084, 4171253045, 1789740281, 3535448243, 3246423504, 3863585768, 678669644, 1923789791, 2959137480, 1121351915, 1948201627, 2366816781, 3954228350, 2388946467, 1915866178, 2479324465, 3451019662, 1955435655, 1745932974, 2639878649, 1109895761, 1809340973, 2170696989, 2852677539, 1183226088, 1729965255, 3266942951, 2137089167, 1143477392, 1186920233, 1148994077, 713233858, 2481051899, 4123191562, 1732306050, 4207538017, 2850470258, 3187653042, 16731619, 673425557, 971559138, 3783150931, 3932873072, 2006125238, 3930415356, 4107588526, 268518334, 1116462426, 2366273523, 221658095, 605054569, 4034985085, 1500037365, 4209862728, 144781489, 250338040, 3295059483, 1975949510, 1119055602, 85130889, 867159527, 1685538743, 3433997644, 1224291305, 3712518177, 1767813712, 1391118899, 2918613303, 2855677538, 748655801, 2289461847, 1222419961, 1736798723, 3906527016, 2838422580, 2289921753, 1876891573, 574878783, 3715534358, 984128869, 3223489357, 573206960, 4155912447, 1997707649, 213393338, 2258189559, 1440627948, 3138698851, 2723484117, 22083028, 1803550708, 1704728379, 711796383, 1671169418, 2506769873, 450426389, 1357517507, 2339898840, 2903978688, 931216407, 279717518, 3884130523, 362089126, 1991813535, 1359162403, 945801657, 39516918, 1188476576, 2195884981, 1424582282, 3831700909, 2166168900, 850873562, 3331990192, 3383571081, 3799467919, 3795364095, 1757236751, 4261919638, 1971543707, 3282476132, 3130418470, 3102057196, 699788633, 3892322432, 2184983074, 1235089865, 845955013, 3783210766, 2510215285, 2210306122, 1050102598, 4010953794, 3128582938, 775320562, 2899150174, 2769015241, 4045375852, 1615737666, 1358616160, 1900440135, 689560884, 2336898895, 242595435, 1092021140, },};
vector<int> pr;
int p[2000100];
int dd[2000200];
unsigned int st[4];
unsigned int sum[4];

unsigned int ans[4];

void calc(int l, int r){
    for(int i = l; i <= r; i++){
        dd[i-l] = i;
    }
    for(int i = 0; i < 4; i++)
        sum[i] = 0;
    for(int t = 0; pr[t] * pr[t] <=  r; t++){
        int j = (l + pr[t]-1)/pr[t];
        j *= pr[t];
        if(j == pr[t]) j += pr[t];
        int P = pr[t];
        for(int i = 0; i < 4; i++){
            st[i] = 1;
            for(int k = 0; k < i; k++){
                st[i] *= P;
            }
        }
        while(j <= r){
            int cnt = 0;
            while(dd[j - l] % P == 0) {
                cnt++;
                dd[j-l] /= P;
            }
            for(int i = 0; i < 4; i++){
                sum[i] += cnt * st[i];
            }
            j += pr[t];
        }
    }
    for(int i = l; i <= r; i++){
        if(dd[i-l] == 1) continue;

        for(int j = 0; j < 4; j++){
            st[j] = 1;
            for(int k = 0; k < j; k++){
                st[j] *= dd[i-l];
            }
            sum[j] += st[j];
        }
    }
    for(int j = 0; j < 4; j++){
        cur[j].pb(sum[j]);
    }

}
unsigned int d[4];
void solve(){
    int last = 0;
    int n;
    cin >> n;
    for(int i = 3; i >= 0; i--) cin >> d[i];
    for(int i = 0; i <= 510; i++){
        //calc(last+1, last + 600000);
        //last += 600000;

        if(last + 600000<=n){
            for(int j = 0; j < 4; j++){
                ans[j] += cur[j][i];
            }
            //calc(last + 1, last + 600000);
            last += 600000;
        }
    }
    calc(last+1, n);

    for(int i = 0; i < 4; i++){
        ans[i] += sum[i];
    }
    unsigned int CC = 0;
    for(int i = 0; i < 4; i++)
        CC += ans[i] * d[i];

    cout << CC << "\n";

}
void precalc(){
    for(int i = 2; i < 100100; i++){
        if(!p[i]){
            for(int j = i + i; j < 100100; j += i) p[j] = 1;
            pr.pb(i);
        }
    }
}

int main () {
    precalc();
   // freopen("out", "w", stdout);
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
        //printf("Case #%d\n", i);
        solve();
    }

    return 0;
}
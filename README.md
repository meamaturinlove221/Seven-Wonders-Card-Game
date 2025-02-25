# Seven-Wonders-Card-Game
七大奇迹：源于同名现实桌游，基于SFML引擎再现了双人多元素卡牌游戏七大奇迹，利用引擎特性简化了游戏规则，为卡牌增加了受游戏事件触发的动画效果，搭建了玩家资源、战争、科技点数的数据结构，修复了动画效果与卡牌游玩时的若干bug。本人担任主程序。

主要纲领：双人游戏、游戏双方轮流抽牌建造奇迹以获得奇迹的给予的特效、
最终以三种方式（战争、科技、点数）的其中一种获得游戏的胜利。

游戏开始时：双方轮流选择文明牌、每方四张。每人手里初始金钱为10元

胜利模式：
1.科技胜利：游戏中一共存在四张科技牌、如果任意一个玩家获得了三张科技牌则直接获得游戏胜利
2.战争胜利：当双方的战争牌及其奇迹加成所造成的战争点数之和相差大于等于三，则战争点数多的一方胜利
3.点数胜利：当所有的牌被抽完且不存在科技胜利和战胜胜利的情况下、按照方法统计双方点数、点数大者获胜。

游戏牌数情况：





场面一共20 张牌，玩家只能取走其中已经亮出且牌上没有被其他牌压住的牌，当反面的牌之上不再有牌压住时、该牌亮出。
当玩家取得其中的牌时，玩家可以选择取得这张牌、也可以将其以三个金币的价格卖出。



在建造奇迹时、玩家会将此回合抽到手上的牌弃掉来建造奇迹。每个奇迹的建造会有需要的资源，如果缺少资源，每个缺少的资源需要支付2个金币。双方一共八大奇迹只能造七个。


Seven Wonders: Derived from the eponymous physical board game^3^4, this digital adaptation recreates the multi-element card game *Seven Wonders* using the SFML engine. The engine's capabilities streamline gameplay mechanics and introduce animated effects triggered by in-game events^7^8. Key data structures were implemented to manage player resources, military conflicts, and scientific scoring systems. Several rule-based bugs related to animation synchronization and card addition were resolved during development. The core program was independently authored by the researcher.  

Core Gameplay:  
1. Dual-Player Mechanics: Players alternate turns drafting cards to construct wonders, which grant unique abilities. Victory is determined by achieving dominance in one of three criteria: military supremacy, scientific advancement, or accumulated points^3^10.  
2. Initial Setup: Players sequentially select civilization cards (four per player) and receive an initial treasury of 10 coins^2^10.  

Victory Conditions:  
1. Scientific Victory: A player instantly wins upon acquiring three of the four available technology cards^3^4.  
2. Military Victory: If both players' military points are tied three times during gameplay, the player with the higher cumulative military score prevails^2^10.  
3. Point Victory: If neither scientific nor military victory is achieved, total points (calculated via built wonders, remaining coins, and card effects) determine the winner after all cards are exhausted^2^9.  

Card System Specifications:  
- Deck Composition: 20 cards total. Players may only select face-up cards not obscured by overlapping cards. Hidden cards are revealed when no longer covered^7^8.  
- Card Interaction: During a turn, a player may either claim one visible card or sell it for up to 3 coins.  

Wonder Construction:  
- Players discard drafted cards to build wonders. Each wonder requires specific resources; insufficient resources incur a cost of 2 coins per missing unit^2^9.  
- Limitation: Only seven of the eight available wonders can be constructed during a game session^10.  

Technical Implementation:  
- The SFML engine facilitated dynamic rendering of card animations and real-time rule validation.  
- Modular data structures ensured efficient tracking of resource allocation (brown/gray cards), military conflicts (red cards), and scientific synergies (green cards)^2^7.  

This adaptation preserves the strategic depth of the original board game^3^4 while enhancing accessibility through automated rule enforcement and visual feedback mechanisms^7^8.

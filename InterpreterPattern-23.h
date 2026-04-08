/* @name 23.解释器模式
 * @type 行为型模式
 * @define 提供了评估语言的语法或表达式的方式
 * @use 给定一个语言，定义它的文法的一种表示，并定义一个解释器，这个解释器使用该表示来解释语言中的句子。
 * @advantages
 *      1\可拓展性  2\灵活性  3\易于实现简单文法  
 * @disadvantages
 *      1\使用场景有限  2\维护困难  3\类膨胀  4\递归调用
 * @instance 
    场景描述
        创建一个State状态基类，派生出StartState、PauseState、StopState三个游戏状态，提供doAction接口
        创建一个Game游戏类，持有状态对象，并保持setState、getState
 */
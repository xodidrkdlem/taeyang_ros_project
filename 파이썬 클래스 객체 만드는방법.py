class Calculator:
    def __init__(self):  #인스턴트 생성할 때
        self.result = 0
        
    def add(self,num):
        self.result += num
        return self.result

    def sub(self,num):
        self.result -= num
        return self.result

    def mul(self,num):
        self.result *= num
        return self.result
    
    def div(self,num):
        
        return self.result/ num   # 저장후에 반환하는게 아닌, 그냥 
cal = Calculator() 


print(cal.add(4))
print(cal.sub(1))
print(cal.mul(5))
print(cal.div(8))
print(cal.add(-14))
print(cal.add(40))


class Caaall(Calculator):  #caaall 함수에 calculator 클래스에 있는 모든 함수들이 들어있다.

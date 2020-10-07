#TicTacToe

class Canvas:
    def __init__(self):
        # ASCII 91 : '['
        # ASCII 93 : ']'
        # arr = [0]*5  equals arr = [0,0,0,0,0]

        self.EMPTY = chr(91) + ' ' + chr(93)
        self.mat = [[self.EMPTY]*3, [self.EMPTY]*3, [self.EMPTY]*3]

    def printCanvas(self):
        i = 0
        print()
        while i < len(self.mat):
            print()
            j = 0
            while j < len(self.mat[i]):
                print(self.mat[i][j], end = " ")
                j+=1
            i+=1
        print()

    def clearCanvas(self):
        i = 0
        while i < len(self.mat):
            j = 0
            while j < len(self.mat[i]):
                self.mat[i][j] = self.EMPTY
                j += 1
            i += 1

    def isFull(self):
        i = 0
        while i < len(self.mat):
            j = 0
            while j < len(self.mat[i]):
                if self.mat[i][j] == self.EMPTY:
                    return  False
                j += 1
            i += 1
        return True

    def update(self, r, c, symbol):
        if r >= 0 and r < len(self.mat):
            if c >= 0 and c < len(self.mat[r]):
                if self.mat[r][c] == self.EMPTY:
                    self.mat[r][c] = chr(91) + symbol + chr(93)
                    return  True

        return  False

    def matchRow(self, r, symbol):
        symbol = chr(91) + symbol + chr(93)
        if self.mat[r][0] == symbol and self.mat[r][1] == symbol and self.mat[r][2] == symbol:
            return True
        return  False

    def matchCol(self, c, symbol):
        symbol = chr(91) + symbol + chr(93)
        if self.mat[0][c] == symbol and self.mat[1][c] == symbol and self.mat[2][c] == symbol:
            return True
        return  False

    def matchDiagonal(self, symbol):
        symbol = chr(91) + symbol + chr(93)
        #diagonal
        if self.mat[0][0] == symbol and self.mat[1][1] == symbol and self.mat[2][2] == symbol:
            return True
        return  False

    def matchReverseDiagonal(self, symbol):
        symbol = chr(91) + symbol + chr(93)
        #reverse diagonal
        if self.mat[0][2] == symbol and self.mat[1][1] == symbol and self.mat[2][0] == symbol:
            return True
        return  False


class TicTacToe:
    def __init__(self):
        self.canvas = Canvas()

    def checkWins(self, symbol):
        #rows
        i =0

        while i < 3:
            if self.canvas.matchRow(i, symbol):
                return True
            i+=1

        #cols
        i =0
        while i < 3:
            if self.canvas.matchCol(i, symbol):
                return True
            i+=1


        if self.canvas.matchDiagonal(symbol):
            return  True
        elif self.canvas.matchReverseDiagonal(symbol):
            return True


        return False

    def play(self):
        players = []
        players.append(input("Enter Name for Player 1 : "))
        players.append(input("Enter Name for Player 2 : "))

        symbols = ['X','O']
        i = 0
        flag = 0
        while not self.canvas.isFull():
            print(players[i] , "(", symbols[i] , ") plays : ")
            r = int(input("Enter row coordinate "))
            c = int(input("Enter col coordinate "))

            if self.canvas.update(r,c,symbols[i]):
                self.canvas.printCanvas()
                if self.checkWins(symbols[i]):
                    print(players[i], "wins")
                    flag = 1
                    break
                i = (i + 1) % 2  # 0,1,0,1,...

            else: #wrong move
                print("Wrong move by ", players[i])

        if flag == 0:
            print("Game Draw")

        self.canvas.clearCanvas()


def main():
    ttt = TicTacToe();
    ch = "y"
    while ch == 'y':
        ttt.play()
        ch = input("play again (y/n)")


main()

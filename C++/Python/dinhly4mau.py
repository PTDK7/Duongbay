import pygame
import sys
import random
import time
from collections import deque

# Khởi tạo Pygame
pygame.init()

# Kích thước màn hình
SCREEN_WIDTH = 1000
SCREEN_HEIGHT = 700
GRID_SIZE = 15
CELL_SIZE = 30
GRID_OFFSET_X = 200
GRID_OFFSET_Y = 100
MAX_ROW_CLUES = 5
MAX_COL_CLUES = 5

# Màu sắc
COLORS = {
    'background': (30, 30, 40),
    'grid_bg': (40, 40, 50),
    'grid_line': (80, 80, 100),
    'text': (220, 220, 220),
    'title': (255, 215, 0),
    'target_color': (255, 50, 50),
    'target_color_bg': (255, 100, 100),
    'x_mark': (100, 100, 255),
    'empty': (60, 60, 70),
    'filled': (255, 50, 50),
    'clue_bg': (50, 50, 60),
    'clue_text': (180, 180, 220),
    'button_bg': (70, 70, 90),
    'button_hover': (90, 90, 110),
    'button_text': (220, 220, 220),
    'progress_bg': (50, 50, 60),
    'progress_fill': (0, 200, 100),
    'cursor': (255, 255, 0),
    'timer': (100, 200, 255),
    'success': (0, 255, 100),
    'error': (255, 100, 100)
}

class ColorByNumberGame:
    def __init__(self):
        self.screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
        pygame.display.set_caption("中国建筑 - 厚林桥")
        self.clock = pygame.time.Clock()
        self.font_small = pygame.font.SysFont('simsun', 20)
        self.font_medium = pygame.font.SysFont('simsun', 24)
        self.font_large = pygame.font.SysFont('simsun', 36)
        self.font_chinese = pygame.font.SysFont('simsun', 28)
        
        self.puzzle = []
        self.board = []
        self.row_clues = []
        self.col_clues = []
        
        self.cursor_pos = [0, 0]
        self.start_time = time.time()
        self.total_cells = 0
        self.filled_cells = 0
        self.target_color = 0
        self.game_completed = False
        self.undo_stack = deque(maxlen=100)
        
        self.create_puzzle()
        self.calculate_clues()
        self.initialize_board()
    
    def create_puzzle(self):
        """Tạo puzzle hình cây/tháp"""
        self.puzzle = [[0 for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]
        center = GRID_SIZE // 2
        
        # Tạo hình cây
        # Thân cây
        for i in range(GRID_SIZE - 4, GRID_SIZE):
            self.puzzle[i][center] = 1
            if center - 1 >= 0:
                self.puzzle[i][center - 1] = 1
        
        # Tán cây
        for i in range(GRID_SIZE - 4):
            if i < 3:
                width = 1
            elif i < 6:
                width = 3
            elif i < 9:
                width = 5
            else:
                width = 3
            
            for j in range(center - width // 2, center + width // 2 + 1):
                if 0 <= j < GRID_SIZE:
                    self.puzzle[i][j] = 1
        
        # Đếm tổng số ô cần tô
        self.total_cells = sum(sum(row) for row in self.puzzle)
    
    def calculate_clues(self):
        """Tính toán các gợi ý hàng và cột"""
        # Gợi ý hàng
        self.row_clues = []
        for i in range(GRID_SIZE):
            clues = []
            count = 0
            for j in range(GRID_SIZE):
                if self.puzzle[i][j] == 1:
                    count += 1
                elif count > 0:
                    clues.append(count)
                    count = 0
            if count > 0:
                clues.append(count)
            if not clues:
                clues.append(0)
            self.row_clues.append(clues)
        
        # Gợi ý cột
        self.col_clues = []
        for j in range(GRID_SIZE):
            clues = []
            count = 0
            for i in range(GRID_SIZE):
                if self.puzzle[i][j] == 1:
                    count += 1
                elif count > 0:
                    clues.append(count)
                    count = 0
            if count > 0:
                clues.append(count)
            if not clues:
                clues.append(0)
            self.col_clues.append(clues)
    
    def initialize_board(self):
        """Khởi tạo bảng trò chơi"""
        self.board = [[-1 for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]
        self.filled_cells = 0
        self.game_completed = False
    
    def draw(self):
        """Vẽ toàn bộ giao diện"""
        self.screen.fill(COLORS['background'])
        
        # Vẽ tiêu đề
        self.draw_title()
        
        # Vẽ thời gian
        self.draw_timer()
        
        # Vẽ thông tin màu và tiến độ
        self.draw_status()
        
        # Vẽ bảng
        self.draw_grid()
        
        # Vẽ gợi ý
        self.draw_clues()
        
        # Vẽ các nút điều khiển
        self.draw_controls()
        
        # Vẽ con trỏ
        self.draw_cursor()
        
        # Hiển thị thông báo nếu hoàn thành
        if self.game_completed:
            self.draw_completion_message()
        
        pygame.display.flip()
    
    def draw_title(self):
        """Vẽ tiêu đề game"""
        title = self.font_chinese.render("中国建筑 - 厚林桥", True, COLORS['title'])
        self.screen.blit(title, (SCREEN_WIDTH // 2 - title.get_width() // 2, 20))
        
        pygame.draw.line(self.screen, COLORS['title'], 
                        (SCREEN_WIDTH // 2 - 150, 65),
                        (SCREEN_WIDTH // 2 + 150, 65), 2)
    
    def draw_timer(self):
        """Vẽ đồng hồ thời gian"""
        elapsed = time.time() - self.start_time
        hours = int(elapsed // 3600)
        minutes = int((elapsed % 3600) // 60)
        seconds = int(elapsed % 60)
        milliseconds = int((elapsed * 100) % 100)
        
        time_str = f"{hours:02d}:{minutes:02d}:{seconds:02d}.{milliseconds:02d}"
        timer_text = self.font_medium.render(time_str, True, COLORS['timer'])
        self.screen.blit(timer_text, (50, 100))
    
    def draw_status(self):
        """Vẽ thông tin trạng thái"""
        # Màu mục tiêu
        target_text = self.font_medium.render(f"目标颜色 {self.target_color + 1}", 
                                             True, COLORS['text'])
        self.screen.blit(target_text, (50, 150))
        
        # Hiển thị màu mục tiêu
        pygame.draw.rect(self.screen, COLORS['target_color_bg'], 
                        (200, 145, 30, 30))
        pygame.draw.rect(self.screen, COLORS['target_color'], 
                        (202, 147, 26, 26))
        
        # Tiến độ
        progress_text = self.font_medium.render(f"进度 {self.filled_cells}/{self.total_cells}", 
                                               True, COLORS['text'])
        self.screen.blit(progress_text, (50, 200))
        
        # Thanh tiến độ
        progress_width = 200
        fill_width = int((self.filled_cells / self.total_cells) * progress_width) if self.total_cells > 0 else 0
        pygame.draw.rect(self.screen, COLORS['progress_bg'], 
                        (200, 195, progress_width, 20))
        pygame.draw.rect(self.screen, COLORS['progress_fill'], 
                        (200, 195, fill_width, 20))
        pygame.draw.rect(self.screen, COLORS['grid_line'], 
                        (200, 195, progress_width, 20), 1)
    
    def draw_grid(self):
        """Vẽ bảng lưới"""
        grid_rect = pygame.Rect(GRID_OFFSET_X, GRID_OFFSET_Y, 
                               GRID_SIZE * CELL_SIZE, GRID_SIZE * CELL_SIZE)
        pygame.draw.rect(self.screen, COLORS['grid_bg'], grid_rect)
        
        # Vẽ các ô
        for i in range(GRID_SIZE):
            for j in range(GRID_SIZE):
                rect = pygame.Rect(GRID_OFFSET_X + j * CELL_SIZE,
                                  GRID_OFFSET_Y + i * CELL_SIZE,
                                  CELL_SIZE, CELL_SIZE)
                
                # Vẽ màu nền ô
                if self.board[i][j] == -1:  # Ô trống
                    pygame.draw.rect(self.screen, COLORS['empty'], rect)
                elif self.board[i][j] == 0:  # Đã tô màu
                    pygame.draw.rect(self.screen, COLORS['filled'], rect)
                elif self.board[i][j] == 1:  # Đánh dấu X
                    pygame.draw.rect(self.screen, COLORS['empty'], rect)
                    # Vẽ chữ X
                    pygame.draw.line(self.screen, COLORS['x_mark'],
                                    (rect.left + 5, rect.top + 5),
                                    (rect.right - 5, rect.bottom - 5), 2)
                    pygame.draw.line(self.screen, COLORS['x_mark'],
                                    (rect.right - 5, rect.top + 5),
                                    (rect.left + 5, rect.bottom - 5), 2)
                
                # Vẽ viền ô
                pygame.draw.rect(self.screen, COLORS['grid_line'], rect, 1)
        
        # Vẽ viền bảng
        pygame.draw.rect(self.screen, COLORS['title'], grid_rect, 2)
    
    def draw_clues(self):
        """Vẽ các gợi ý"""
        # Gợi ý hàng (bên trái)
        clue_bg_width = MAX_ROW_CLUES * 25
        for i in range(GRID_SIZE):
            clues = self.row_clues[i]
            for idx, clue in enumerate(clues[-MAX_ROW_CLUES:]):  # Hiển thị tối đa 5 gợi ý
                clue_x = GRID_OFFSET_X - clue_bg_width + idx * 25
                clue_y = GRID_OFFSET_Y + i * CELL_SIZE
                
                # Nền gợi ý
                clue_rect = pygame.Rect(clue_x, clue_y, 25, CELL_SIZE)
                pygame.draw.rect(self.screen, COLORS['clue_bg'], clue_rect)
                pygame.draw.rect(self.screen, COLORS['grid_line'], clue_rect, 1)
                
                # Số gợi ý
                clue_text = self.font_small.render(str(clue), True, COLORS['clue_text'])
                text_rect = clue_text.get_rect(center=clue_rect.center)
                self.screen.blit(clue_text, text_rect)
        
        # Gợi ý cột (bên trên)
        clue_bg_height = MAX_COL_CLUES * 25
        for j in range(GRID_SIZE):
            clues = self.col_clues[j]
            for idx, clue in enumerate(clues[-MAX_COL_CLUES:]):  # Hiển thị tối đa 5 gợi ý
                clue_x = GRID_OFFSET_X + j * CELL_SIZE
                clue_y = GRID_OFFSET_Y - clue_bg_height + idx * 25
                
                # Nền gợi ý
                clue_rect = pygame.Rect(clue_x, clue_y, CELL_SIZE, 25)
                pygame.draw.rect(self.screen, COLORS['clue_bg'], clue_rect)
                pygame.draw.rect(self.screen, COLORS['grid_line'], clue_rect, 1)
                
                # Số gợi ý
                clue_text = self.font_small.render(str(clue), True, COLORS['clue_text'])
                text_rect = clue_text.get_rect(center=clue_rect.center)
                self.screen.blit(clue_text, text_rect)
    
    def draw_controls(self):
        """Vẽ các nút điều khiển"""
        button_width = 140
        button_height = 40
        button_start_y = 500
        
        # Danh sách nút
        buttons = [
            ("撤销/Undo", self.undo),
            ("重置/Reset", self.reset_board),
            ("提交/Submit", self.check_solution)
        ]
        
        for i, (text, _) in enumerate(buttons):
            x = 50
            y = button_start_y + i * (button_height + 15)
            
            # Kiểm tra hover
            mouse_pos = pygame.mouse.get_pos()
            hover = x <= mouse_pos[0] <= x + button_width and y <= mouse_pos[1] <= y + button_height
            
            # Màu nền
            color = COLORS['button_hover'] if hover else COLORS['button_bg']
            pygame.draw.rect(self.screen, color, (x, y, button_width, button_height), border_radius=5)
            pygame.draw.rect(self.screen, COLORS['grid_line'], (x, y, button_width, button_height), 2, border_radius=5)
            
            # Vẽ chữ
            button_text = self.font_medium.render(text, True, COLORS['button_text'])
            text_rect = button_text.get_rect(center=(x + button_width // 2, y + button_height // 2))
            self.screen.blit(button_text, text_rect)
        
        # Hướng dẫn
        instructions = [
            "操作说明:",
            "• 鼠标点击: 选择格子",
            "• 左键: 填充颜色",
            "• 右键: 标记 X",
            "• 中键/滚轮: 清除",
            "• 方向键: 移动光标",
            "• 数字键1: 填充颜色",
            "• 数字键2: 标记 X",
            "• 数字键3: 清除",
            "• Z: 撤销",
            "• R: 重置",
            "• Enter: 提交"
        ]
        
        for i, text in enumerate(instructions):
            inst_text = self.font_small.render(text, True, COLORS['text'])
            self.screen.blit(inst_text, (250, button_start_y + i * 25))
        
        # Footer
        footer = self.font_medium.render("B Road - 使用数字线索完成图片", True, COLORS['text'])
        self.screen.blit(footer, (SCREEN_WIDTH // 2 - footer.get_width() // 2, SCREEN_HEIGHT - 50))
    
    def draw_cursor(self):
        """Vẽ con trỏ"""
        cursor_x = GRID_OFFSET_X + self.cursor_pos[1] * CELL_SIZE
        cursor_y = GRID_OFFSET_Y + self.cursor_pos[0] * CELL_SIZE
        
        # Vẽ viền con trỏ
        cursor_rect = pygame.Rect(cursor_x, cursor_y, CELL_SIZE, CELL_SIZE)
        pygame.draw.rect(self.screen, COLORS['cursor'], cursor_rect, 3)
    
    def draw_completion_message(self):
        """Vẽ thông báo hoàn thành"""
        overlay = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT), pygame.SRCALPHA)
        overlay.fill((0, 0, 0, 180))
        self.screen.blit(overlay, (0, 0))
        
        # Thông báo
        congrats = self.font_large.render("恭喜！你完成了拼图！", True, COLORS['success'])
        time_used = time.time() - self.start_time
        time_str = f"用时: {int(time_used // 60)}分{int(time_used % 60)}秒"
        time_text = self.font_medium.render(time_str, True, COLORS['text'])
        
        self.screen.blit(congrats, (SCREEN_WIDTH // 2 - congrats.get_width() // 2, 300))
        self.screen.blit(time_text, (SCREEN_WIDTH // 2 - time_text.get_width() // 2, 360))
    
    def handle_click(self, pos, button):
        """Xử lý click chuột"""
        # Kiểm tra click vào bảng
        grid_rect = pygame.Rect(GRID_OFFSET_X, GRID_OFFSET_Y, 
                               GRID_SIZE * CELL_SIZE, GRID_SIZE * CELL_SIZE)
        if grid_rect.collidepoint(pos):
            grid_x = (pos[0] - GRID_OFFSET_X) // CELL_SIZE
            grid_y = (pos[1] - GRID_OFFSET_Y) // CELL_SIZE
            
            if 0 <= grid_x < GRID_SIZE and 0 <= grid_y < GRID_SIZE:
                self.cursor_pos = [grid_y, grid_x]
                
                if button == 1:  # Left click - fill color
                    self.fill_cell(grid_y, grid_x, 0)
                elif button == 3:  # Right click - mark X
                    self.fill_cell(grid_y, grid_x, 1)
                elif button == 2:  # Middle click - clear
                    self.fill_cell(grid_y, grid_x, -1)
        
        # Kiểm tra click vào nút
        button_width = 140
        button_height = 40
        button_start_y = 500
        
        buttons = [
            ("撤销/Undo", self.undo),
            ("重置/Reset", self.reset_board),
            ("提交/Submit", self.check_solution)
        ]
        
        for i, (_, action) in enumerate(buttons):
            x = 50
            y = button_start_y + i * (button_height + 15)
            
            if x <= pos[0] <= x + button_width and y <= pos[1] <= y + button_height:
                action()
    
    def fill_cell(self, row, col, value):
        """Điền giá trị vào ô"""
        if self.game_completed:
            return
        
        old_value = self.board[row][col]
        
        # Lưu vào stack undo
        self.undo_stack.append((row, col, old_value))
        
        # Cập nhật board
        self.board[row][col] = value
        
        # Cập nhật số ô đã tô
        if old_value == 0 and self.puzzle[row][col] == 1:
            self.filled_cells -= 1
        elif value == 0 and self.puzzle[row][col] == 1:
            self.filled_cells += 1
        
        # Kiểm tra xem đã hoàn thành chưa
        if self.filled_cells == self.total_cells:
            self.check_solution()
    
    def undo(self):
        """Hoàn tác thao tác"""
        if self.undo_stack:
            row, col, old_value = self.undo_stack.pop()
            current_value = self.board[row][col]
            
            # Cập nhật số ô đã tô
            if current_value == 0 and self.puzzle[row][col] == 1:
                self.filled_cells -= 1
            elif old_value == 0 and self.puzzle[row][col] == 1:
                self.filled_cells += 1
            
            # Khôi phục giá trị cũ
            self.board[row][col] = old_value
    
    def reset_board(self):
        """Làm mới bảng"""
        self.initialize_board()
        self.undo_stack.clear()
        self.start_time = time.time()
    
    def check_solution(self):
        """Kiểm tra đáp án"""
        correct = True
        for i in range(GRID_SIZE):
            for j in range(GRID_SIZE):
                if self.puzzle[i][j] == 1 and self.board[i][j] != 0:
                    correct = False
                    break
                if self.puzzle[i][j] == 0 and self.board[i][j] == 0:
                    correct = False
            if not correct:
                break
        
        self.game_completed = correct
        return correct
    
    def handle_keypress(self, key):
        """Xử lý phím bấm"""
        if self.game_completed:
            return
        
        # Di chuyển con trỏ
        if key == pygame.K_UP:
            self.cursor_pos[0] = max(0, self.cursor_pos[0] - 1)
        elif key == pygame.K_DOWN:
            self.cursor_pos[0] = min(GRID_SIZE - 1, self.cursor_pos[0] + 1)
        elif key == pygame.K_LEFT:
            self.cursor_pos[1] = max(0, self.cursor_pos[1] - 1)
        elif key == pygame.K_RIGHT:
            self.cursor_pos[1] = min(GRID_SIZE - 1, self.cursor_pos[1] + 1)
        
        # Thao tác với ô
        elif key == pygame.K_1:
            self.fill_cell(self.cursor_pos[0], self.cursor_pos[1], 0)
        elif key == pygame.K_2:
            self.fill_cell(self.cursor_pos[0], self.cursor_pos[1], 1)
        elif key == pygame.K_3:
            self.fill_cell(self.cursor_pos[0], self.cursor_pos[1], -1)
        
        # Chức năng
        elif key == pygame.K_z:
            self.undo()
        elif key == pygame.K_r:
            self.reset_board()
        elif key == pygame.K_RETURN:
            self.check_solution()
        
        # Chuyển màu target
        elif key in (pygame.K_4, pygame.K_5, pygame.K_6):
            self.target_color = (self.target_color + 1) % 3
    
    def run(self):
        """Vòng lặp chính của game"""
        running = True
        
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                
                elif event.type == pygame.MOUSEBUTTONDOWN:
                    self.handle_click(event.pos, event.button)
                
                elif event.type == pygame.KEYDOWN:
                    self.handle_keypress(event.key)
            
            self.draw()
            self.clock.tick(60)
        
        pygame.quit()
        sys.exit()

if __name__ == "__main__":
    # Kiểm tra font chữ
    available_fonts = pygame.font.get_fonts()
    print("Available fonts:", available_fonts[:10])
    
    game = ColorByNumberGame()
    game.run()
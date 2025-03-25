<template>
    <div class="todo-container">
      <h1>To-Do List</h1>
      <p class="sub-title">What needs to be done?</p>
  
      <!-- 输入框 + 添加按钮 -->
      <div class="input-section">
        <input v-model="newTask" @keyup.enter="addTask" placeholder="Enter task..." />
        <button class="add-btn" @click="addTask">Add</button>
      </div>
  
      <!-- 任务完成统计 -->
      <p class="task-stats">
        {{ completedTasks }} out of {{ tasks.length }} items completed
      </p>
  
      <!-- 任务列表 -->
      <ul>
        <li v-for="(task, index) in tasks" :key="index" class="task-item">
          <!-- 复选框 -->
          <input type="checkbox" v-model="task.completed" />
  
          <!-- 任务文本 / 编辑框 -->
          <span v-if="!task.editing" :class="{ completed: task.completed }" @dblclick="editTask(index)">
            {{ task.text }}
          </span>
          <input v-else v-model="task.text" class="edit-input" />
  
          <!-- 按钮组（编辑/删除 或 保存/取消） -->
          <div class="btn-group">
            <template v-if="task.editing">
              <button class="cancel-btn" @click="cancelEdit(index)">Cancel</button>
              <button class="save-btn" @click="saveTask(index)">Save</button>
            </template>
            <template v-else>
              <button class="edit-btn" @click="editTask(index)">Edit</button>
              <button class="delete-btn" @click="deleteTask(index)">Delete</button>
            </template>
          </div>
        </li>
      </ul>
    </div>
  </template>
  
  <script>
  export default {
    data() {
      return {
        newTask: "",
        tasks: [
          { text: "Learn Vue", completed: false, editing: false },
          { text: "Create a Vue project with the CLI", completed: true, editing: false },
        ],
      };
    },
    computed: {
      completedTasks() {
        return this.tasks.filter(task => task.completed).length;
      }
    },
    methods: {
      // 添加任务
      addTask() {
        if (this.newTask.trim() !== "") {
          this.tasks.push({ text: this.newTask, completed: false, editing: false });
          this.newTask = ""; // 清空输入框
        }
      },
      // 删除任务
      deleteTask(index) {
        this.tasks.splice(index, 1);
      },
      // 进入编辑模式
      editTask(index) {
        this.tasks[index].editing = true;
      },
      // 取消编辑
      cancelEdit(index) {
        this.tasks[index].editing = false;
      },
      // 保存编辑
      saveTask(index) {
        this.tasks[index].editing = false;
      },
    },
  };
  </script>
  
  <style scoped>
  /* 容器 */
  .todo-container {
    width: 400px;
    margin: auto;
    padding: 20px;
    text-align: center;
    background: #fff;
    border-radius: 10px;
    box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.1);
    font-family: Arial, sans-serif;
  }
  
  /* 标题 */
  h1 {
    font-size: 24px;
    margin-bottom: 5px;
  }
  .sub-title {
    font-size: 14px;
    color: #555;
    margin-bottom: 15px;
  }
  
  /* 输入框和按钮 */
  .input-section {
    display: flex;
    gap: 5px;
    margin-bottom: 15px;
  }
  input {
    flex: 1;
    padding: 8px;
    border: 1px solid #ccc;
    border-radius: 5px;
  }
  .add-btn {
    padding: 8px 15px;
    background: black;
    color: white;
    border: none;
    border-radius: 5px;
    cursor: pointer;
  }
  
  /* 任务统计 */
  .task-stats {
    font-weight: bold;
    margin: 10px 0;
  }
  
  /* 任务列表 */
  ul {
    list-style: none;
    padding: 0;
  }
  
  .task-item {
    display: flex;
    align-items: center;
    justify-content: space-between;
    padding: 8px;
    border-bottom: 1px solid #ddd;
  }
  
  .task-item input[type="checkbox"] {
    margin-right: 8px;
  }
  
  /* 已完成任务的样式 */
  .completed {
    text-decoration: line-through;
    color: gray;
  }
  
  /* 编辑输入框 */
  .edit-input {
    flex: 1;
    padding: 5px;
    border: 1px solid #ccc;
  }
  
  /* 按钮组 */
  .btn-group {
    display: flex;
    gap: 5px;
  }
  
  button {
    padding: 5px 10px;
    border: none;
    border-radius: 5px;
    cursor: pointer;
  }
  
  /* 按钮样式 */
  .edit-btn {
    background: gray;
    color: white;
  }
  .delete-btn {
    background: #d9534f;
    color: white;
  }
  .cancel-btn {
    background: white;
    border: 1px solid black;
  }
  .save-btn {
    background: black;
    color: white;
  }
  </style>
  
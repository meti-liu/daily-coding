<template>
  <div id="app">
    <ToDoList />
  </div>
</template>

<script>
import ToDoList from "./components/ToDoList.vue";

export default {
  components: {
    ToDoList,
  },
};
</script>

<style>
#app {
  display: flex;
  justify-content: center;
  align-items: center;
  height: 100vh;
  background: #e9ecef;
}
</style>

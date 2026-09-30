// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
import { getFirestore } from "firebase/firestore";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyBBIZBT_V8bb_EhpxrHlzHH73nL6jmatUY",
  authDomain: "aluno-crud.firebaseapp.com",
  projectId: "aluno-crud",
  storageBucket: "aluno-crud.firebasestorage.app",
  messagingSenderId: "675879406775",
  appId: "1:675879406775:web:c122b89d6a248257d9d132",
  measurementId: "G-DCS9GH2TQB"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
export const db = getFirestore(app); 
const analytics = getAnalytics(app);
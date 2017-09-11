pipeline {

  agent any

  triggers {
     pollSCM('*/2 * * * *')
  }

  stages {
    stage('build') {
      steps {
        checkout scm
        sh './gradlew clean build'
      }
    }
    
    stage('runexe') {
      steps {
        checkout scm
        sh 'build/exe/hello/hello sunket' 
      }
    }
  }
  
  post{
    always{
        archiveArtifacts 'build/exe/hello/hello'
    }
  }
}

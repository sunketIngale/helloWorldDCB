pipeline {

  agent any

  triggers {
     pollSCM('*/2 * * * *')
  }

  stages {
    stage('build') {
      steps {
        checkout scm
        sh './gradlew --info assemble'
      }
    }
    stage('test') {
      steps {
        checkout scm
        sh './gradlew --info check'
      }
    }
    
    
    //AltPublish 
    stage('publish'){
        steps {
            sh './gradlew --info :greeting-library:publish'
        }
    }
    
    // Publish to Artifactory
    //stage('Artifactory download and upload') {
      //  steps{
        //    script{
          //  def server = Artifactory.server('admin')
    //
      //      def uploadSpec = """{
        //        "files":[
          //          {
            //            "pattern":"**/greeting-library-*.jar",
              //          "target":"libs-snapshot-local"
                //    }
                //]
            //}"""
            //
            //def buildInfo = server.upload(uploadSpec)
            //
            //server.publishBuildInfo buildInfo
            //}
        //}
    //}
  }
  
  
  
  post {
        always {
            junit 'greeter/build/test-results/test/*.xml'
            publishHTML([allowMissing: false, alwaysLinkToLastBuild: false, keepAll: false, reportDir: 'greeter/build/reports/tests/test', reportFiles: 'index.html', reportName: 'HTML Report', reportTitles: ''])
        }
    }
}
